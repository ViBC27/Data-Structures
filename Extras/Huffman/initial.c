#include <stdio.h>
#include <string.h>

void encode() {
  printf("Encode.\n");
}

void decode() {
  printf("Decode.\n");
}

void help() {
  printf("USAGE:\n");
  printf("  VERDZIP [OPTION] [FILE] [PARAMETERS]\n");
  
  printf("\n");
  printf("APPLICATION OPTIONS:\n");
  printf("-e, --encode\t\tEncode a file.\n");
  printf("-d, --decode\t\tDecode a file.\n");
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

int stringEquality(char *S1, char *S2) {
  return strcmp(S1, S2);
}

int main(int argc, char *argv[]) {

  if(argc == 1) {
    printf("Uso principal.\n");
  }
  else if(argc == 2) {
    if(stringEquality(argv[1], "-h") == 0) help();
    else if(stringEquality(argv[1], "--help") == 0) help();
    else if(stringEquality(argv[1], "-v") == 0) version();
    else if(stringEquality(argv[1], "--version") == 0) version();
    else if(stringEquality(argv[1], "-e") == 0) encode();
    else if(stringEquality(argv[1], "--encode") == 0) encode();
    else if(stringEquality(argv[1], "-d") == 0) decode();
    else if(stringEquality(argv[1], "--decode") == 0) decode();
    else {
      printf("%s: Unknown option.\n", argv[1]);
    }

  }
  else if(argc == 3) {}
  else {}
  return 0;
}