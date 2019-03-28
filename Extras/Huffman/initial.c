#include <stdio.h>
#include <string.h>

void compress(char *pathFile, char *outputFile) {
  printf("Compress.\n");
}

void descompress(char *pathFile, char *outputFile) {
  printf("Descompress.\n");
}

void help() {
  printf("USAGE:\n");
  printf("  VERDZIP [OPTION] [FILE] [PARAMETERS]\n");
  
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
  printf("VERD v.ALPHA-0.1\n");
}

int main(int argc, char *argv[]) {
  char *command = argv[1];
  char outputFile[100];
  char pathFile[100];

  if(argc == 1) {
    printf("Welcome to VRDZIP.\n");
    printf("Write the path of the file: ");
    scanf("%s", pathFile);
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
    //pathFile = argv[2]; outputFile = argv[3];
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
