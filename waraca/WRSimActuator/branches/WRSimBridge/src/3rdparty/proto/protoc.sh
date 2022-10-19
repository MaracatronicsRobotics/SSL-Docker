cd grSim/
protoc --cpp_out=./ ./*.proto
cd ../VSSSim/
protoc --cpp_out=./ ./*.proto
