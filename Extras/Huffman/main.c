#include <stdio.h>
#include <string.h>
#include "Headers/compress.h"
#include "Headers/descompress.h"

void help() {
  printf("USAGE:\n");
  printf("  VRDZIP [OPTION] [FILE] [PARAMETERS]\n");
  
  printf("\n");
  printf("APPLICATION OPTIONS:\n");
  printf("-c, --compress\t\tcompress a file.\n");
  printf("-d, --descompress\t\tdescompress a file.\n");
  printf("-v, --version\t\tShows the version of the application.\n");
  
  printf("\n");
  printf("HELP OPTIONS:\n");
  printf("-h, --help\t\tShows the help options.\n");
 
  printf("\n");
  printf("PARAMETERS:\n");
  printf("[OUTPUT FORMAT]\t\tOUTPUTS(O): .huff .verd\n");
  printf("-o O, --output O\tOutput file.\n");
}

void version() {
  printf("VRD v.ALPHA-0.1\n");
}

int main(int argc, char *argv[]) {
  char *command = argv[1];
  char outputFile[100];
  char pathFile[100];
  int option;

  if(argc == 1) {
    printf("\nWelcome to VRDZIP.\n\n");
    printf("[1] - Compress;\n");
    printf("[2] - Descompress;\n");
    printf("[3] - Help;\n");
    printf("[4] - Version.\n\n");
    printf("Enter a command: ");
    scanf("%d", &option);
    
    if(option == 1 || option == 2) {
      printf("Write the path of the file: ");
      scanf("%s", pathFile);
      printf("Write the output of the file: ");
      scanf("%s", outputFile);
      if(option == 1) {
        compress(pathFile, outputFile);
      }
      else {
        descompress(pathFile, outputFile);
      }
    }
    else if(option == 3) {
      help();
    }
    else if(option == 4) {
      version();
    }
    else {
      printf("%d: Unknown option.\n", option);
    }
  }
  else if(argc == 2) {
    if(strcmp(command, "-h") == 0) help();
    else if(strcmp(command, "--help") == 0) help();
    else if(strcmp(command, "-v") == 0) version();
    else if(strcmp(command, "--version") == 0) version();
    else {
      printf("%s: Unknown option.\n", command);
    }
  }
  else if(argc == 4) {
    if(strcmp(command, "-c") == 0) compress(pathFile, outputFile);
    else if(strcmp(command, "--compress") == 0) compress(pathFile, outputFile);
    else if(strcmp(command, "-d") == 0) descompress(pathFile, outputFile);
    else if(strcmp(command, "--descompress") == 0) descompress(pathFile, outputFile);
    else {
      printf("%s: Unknown option.\n", command);
    }
  }
  else {
    printf("Unknown options.\n");
  }
  return 0;
}