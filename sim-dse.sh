
mvn  --quiet  org.apache.maven.plugins:maven-dependency-plugin:3.3.0:copy \
 -DremoteRepositories=https://overture.au.dk/artifactory/into-cps \
 -Dartifact=org.into-cps.maestro:maestro:2.2.1-SNAPSHOT:jar:jar-with-dependencies \
 -Dtransitive=false -DoutputDirectory=.


#mabl=/Users/kgl/data/au/into-cps-association/maestro/maestro/target/maestro-2.2.1-SNAPSHOT-jar-with-dependencies.jar
mabl=maestro-2.2.1-SNAPSHOT-jar-with-dependencies.jar


echo "Add the option to generate some parameters as external (config/venv)"
mkdir -p sim-dse
jq '. +={ "environmentParameters": ["{Controller}.cont.maxlevel"]}'  Multi-models/mm/mm.mm.json > sim-dse/mm.json



jenv local 11
echo "Generate the mabl spec"
java -jar $mabl import sg1 -fsp /Users/kgl/data/au/into-cps-association/example-single_watertank/FMUs -output sim-dse Multi-models/mm/co-sim-51/co-sim-51.coe.json sim-dse/mm.json 

echo Interpret the spec using JAVA
#java -jar $mabl interpret -runtime sim-dse/spec.runtime.json sim-dse/spec.mabl

echo Generate native cpp simulator
java -jar $mabl export cpp -output sim-dse/cpp -runtime sim-dse/spec.runtime.json sim-dse/spec.mabl

echo "Running cmake for native cpp simulator - it talkes a while..."
cmake -Bsim-dse/cpp/program -Ssim-dse/cpp
echo Compiling native cpp simulator...
make -Csim-dse/cpp/program -j9

echo Check the program
sim-dse/cpp/program/sim -?

echo Run natime simulation

cat > sim-dse/spec.cpp1.runtime.json << EOT
{
  "environment_variables" : {
    "{Controller}.cont.maxlevel" : 2,
    "{Controller}.cont.minlevel" : 1
  },
  "DataWriter" : [ {
    "filename" : "cpp1-outputs.csv",
    "type" : "CSV"
  } ]
}
EOT


sim-dse/cpp/program/sim -runtime sim-dse/spec.cpp1.runtime.json > cpp1.log

echo Run using env
cat > sim-dse/spec.cpp2.runtime.json << EOT
{
  "DataWriter" : [ {
    "filename" : "cpp2-outputs.csv",
    "type" : "CSV"
  } ]
}
EOT
export Controller_cont_maxlevel=8
sim-dse/cpp/program/sim -runtime sim-dse/spec.cpp2.runtime.json > cpp2.log

cat > sim-dse/spec.cpp3.runtime.json << EOT
{
  "DataWriter" : [ {
    "filename" : "cpp3-outputs.csv",
    "type" : "CSV"
  } ]
}
EOT
export Controller_cont_maxlevel=1
sim-dse/cpp/program/sim  -runtime sim-dse/spec.cpp3.runtime.json > cpp3.log

grep -r "Executed in" cpp*.log

echo Done.