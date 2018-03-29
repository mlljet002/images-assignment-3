#ifndef HEADERFILE
  #define HEADERFILE
  #include "../include/driver.h"
#endif
#include <iostream>


int main(int argc, char *argv[]) {

        Utils::Operations op = Utils::parse_args(argc,argv);
        switch (op) {
        case Utils::Operations::BUILD:
                std::cout << "Building image..." << '\n';
                build(argv);

                break;
        case Utils::Operations::DIFF_MAP:
                std::cout << "Calculating difference map..." << '\n';
                diffmap(argv);


                break;
        case Utils::Operations::EXTRACT:
                std::cout << "Extracting..." << '\n';
                extract(argv);

                break;
        case Utils::Operations::EXTRACT_ACROSS_SLICES:
                std::cout << "Extracting across all slices..." << '\n';
                extractAcrossSlices(argv);

                break;
        case Utils::Operations::FAIL:
                showUsage();
                break;
        }
        return 0;
}


int mockMethod(){
        // Method to test that the test framework works;

        return 1;
}



void build(char* argv[]){
        std::string baseName = argv[1];
        VolImage image;
        image.readRawFiles(baseName);

}

void extract(char* argv[]){
        std::string baseName = argv[1];
        i = atoi(argv[3]);
        output_name = argv[4];
        VolImage image;
        Metadata meta = image.readDataFile(baseName);
        image.writeSliceToFile(image.readSlice(meta,i),meta,output_name);



}

void diffmap(char* argv[]){
        VolImage image;
        std::string baseName = argv[1];
        i = atoi(argv[3]);
        j = atoi(argv[4]);
        output_name = argv[5];
        Metadata meta = image.readDataFile(baseName);
        image.readRawFiles(baseName);
        std::vector<unsigned char**> volume = image.getSlices();
        unsigned char ** slice= image.VectorDifference(meta,volume,i,j);
        image.writeSliceToFile(slice,meta,output_name);


}

void extractAcrossSlices(char* argv[]){
        // VolImage image;
        std::string baseName = argv[1];
        i = atoi(argv[3]);
        output_name = argv[4];
        Metadata meta = image.readDataFile(baseName);
        VolImage image;
        Metadata meta_output(output_name,meta.width,meta.number_of_images,1);
        std::vector<unsigned char**> volume = Utils::readRawFiles(meta);
        // std::cout << (float)volume[0][0][0] << '\n';
        image.writeSliceToFile(image.extractAcrossSlices(meta, volume, i),meta_output,output_name);

}



void showUsage(){
        std::cerr << "Usage: " << "runner" << " <imageBase> -d i j output file name" << std::endl;
        std::cerr << "Usage: " << "runner" << " <imageBase> -x i output file name" << std::endl;
        std::cerr << "Usage: " << "runner" << " <imageBase> -g i output file name" << std::endl;

        std::cerr << "Usage: " << "runner" << " <imageBase>" << std::endl;
}

void showOperationInfo(int num_imgs,int num_bytes){
        std::cout << "Number of images: " <<num_imgs<< '\n';
        std::cout << "Number of bytes required: " <<num_bytes<< '\n';
}
