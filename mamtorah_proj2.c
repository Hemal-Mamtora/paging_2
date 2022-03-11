/*
* Author: Hemal Ketan Mamtora
* Purpose: Project 2, OS, CSCE 611
* Affiliation: Texas A&M University
* 
* Compile and run instructions (Cyberrange) (ensure it is in .c file):
* 
* 1. Goto Appropriate file location: of mamtorah_exam1.c
* 2. Keep mamtorah_proj2_input.txt file (file with stream of memory pages to be considered) in 
*    same directory as the mamtorah_exam1.c 
* 3. Compile:
* user@box:~/Desktop/page_replacement$ gcc mamtorah_exam1.c -o mamtorah_exam1.exe
* 4. Run:
* user@box:~/Desktop/page_replacement$ ./mamtorah_proj1.exe 
* 
* Sample Outputs:
*
* user@box:~/Desktop/page_replacement$ ./mamtorah_exam1.exe 
* Choose a page replacement algorithm:
* Press 1 for FIFO
* Press 2 for LRU
* Press 3 for Second Chance
* Your choice: 1
* Running FIFO:
* Input pages:           0   2   1   3   5   4   6   3   7   4   7   3   3   5   5   3   1   1   1   7   2   3   4   1  
* Memory 1:         -1   0   2   1   3   5   4   6   6   7   7   7   3   3   5   5   5   1   1   1   1   2   2   4   4  
* Memory 2:         -1  -1   0   2   1   3   5   4   4   6   6   6   7   7   3   3   3   5   5   5   5   1   1   2   2  
* Memory 3:         -1  -1  -1   0   2   1   3   5   5   4   4   4   6   6   7   7   7   3   3   3   3   5   5   1   1  
* Memory 4:         -1  -1  -1  -1   0   2   1   3   3   5   5   5   4   4   6   6   6   7   7   7   7   3   3   5   5  
* Recently out 1:   -1  -1  -1  -1  -1   0   2   1   1   3   3   3   5   5   4   4   4   6   6   6   6   7   7   3   3  
* Recently out 2:   -1  -1  -1  -1  -1  -1   0   2   2   1   1   1   3   3   5   5   5   4   4   4   4   6   6   7   7  
* Recently out 3:   -1  -1  -1  -1  -1  -1  -1   0   0   2   2   2   1   1   3   3   3   5   5   5   5   4   4   6   6  
* Recently out 4:   -1  -1  -1  -1  -1  -1  -1  -1  -1   0   0   0   2   2   1   1   1   3   3   3   3   5   5   4   4  
* Pagefault:         0   1   1   1   1   1   1   1   0   1   0   0   1   0   1   0   0   1   0   0   0   1   0   1   0  
* 
* user@box:~/Desktop/page_replacement$ ./mamtorah_exam1.exe 
* Choose a page replacement algorithm:
* Press 1 for FIFO
* Press 2 for LRU
* Press 3 for Second Chance
* Your choice: 2
* Running LRU:
* Input pages:           0   2   1   3   5   4   6   3   7   4   7   3   3   5   5   3   1   1   1   7   2   3   4   1  
* Memory 1:         -1   0   0   0   0   5   5   5   5   7   7   7   7   7   7   7   7   7   7   7   7   7   7   7   1  
* Memory 2:         -1  -1   2   2   2   2   4   4   4   4   4   4   4   4   4   4   4   1   1   1   1   1   1   4   4  
* Memory 3:         -1  -1  -1   1   1   1   1   6   6   6   6   6   6   6   5   5   5   5   5   5   5   2   2   2   2  
* Memory 4:         -1  -1  -1  -1   3   3   3   3   3   3   3   3   3   3   3   3   3   3   3   3   3   3   3   3   3  
* Recently out 1:   -1  -1  -1  -1  -1   0   2   1   1   5   5   5   5   5   6   6   6   4   4   4   4   5   5   1   7  
* Recently out 2:   -1  -1  -1  -1  -1  -1   0   2   2   1   1   1   1   1   5   5   5   6   6   6   6   4   4   5   1  
* Recently out 3:   -1  -1  -1  -1  -1  -1  -1   0   0   2   2   2   2   2   1   1   1   5   5   5   5   6   6   4   5  
* Recently out 4:   -1  -1  -1  -1  -1  -1  -1  -1  -1   0   0   0   0   0   2   2   2   1   1   1   1   5   5   6   4  
* Pagefault:         0   1   1   1   1   1   1   1   0   1   0   0   0   0   1   0   0   1   0   0   0   1   0   1   1  
* 
* user@box:~/Desktop/page_replacement$ ./mamtorah_exam1.exe 
* Choose a page replacement algorithm:
* Press 1 for FIFO
* Press 2 for LRU
* Press 3 for Second Chance
* Your choice: 3
* Running Second Chance:
* Input pages:           0   2   1   3   5   4   6   3   7   4   7   3   3   5   5   3   1   1   1   7   2   3   4   1  
* Memory 1:         -1   0   2   1   3   5   4   6   6   7   7   7   7   7   5   5   5   1   1   1   1   2   3   4   4  
* Memory 2:          0  -1   0   2   1   3   5   4   4   6   6   6   6   6   7   7   7   5   5   5   5   1   1   3   3  
* Memory 3:         -1  -1  -1   0   2   1   3   5   5   4   4   4   4   4   4   4   4   7   7   7   7   5   5   1   1  
* Memory 4:          0  -1  -1  -1   0   2   1   3   3   3   3   3   3   3   3   3   3   3   3   3   3   7   7   5   5  
* Recently out 1:   -1   0   2   1   3   5   4   6   6   7   7   7   7   7   5   5   5   1   1   1   1   2   3   4   4  
* Recently out 2:    0  -1  -1   0   2   1   3   5   5   4   4   4   4   4   4   4   4   7   7   7   7   5   5   1   1  
* Recently out 3:   -1   0   2   1   3   5   4   6   6   7   7   7   7   7   5   5   5   1   1   1   1   2   3   4   4  
* Recently out 4:    0   0   2   1   3   5   4   6   6   7   7   7   7   7   5   5   5   1   1   1   1   2   3   4   4  
* Pagefault:         0   1   1   1   1   1   1   1   0   1   0   0   0   0   1   0   0   1   0   0   0   1   1   1   0  
* user@box:~/Desktop/page_replacement$ 
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define INPUT_SIZE 100

int pageFrameSize;
int *memory;
struct timeval tv;
long long timestamp;

int pageMemoryIndex(int page) {
  for (int i = 0; i < pageFrameSize; i++)
    if (page == memory[i])
      return i;
  return -1;
}

void insert(int page) {
  int temp, current = page;
  for (int i = 0; i < pageFrameSize; i++) {
    temp = memory[i];
    memory[i] = current;
    current = temp;
  }
}

void initializeMemory() {
  for (int i = 0; i < pageFrameSize; i++)
    insert(-1);
}

void FIFO() {
  int page;
  int pageFault = 0;
  int pageFaultCount = 0;

  // Read File
  FILE *fp = fopen("mamtorah_proj2_input.txt", "r");

  if (fp == NULL) {
    perror("Unable to open the file");
    exit(1);
  }

  while (fscanf(fp, "%d", &page) == 1) {
    gettimeofday(&tv,NULL);
    // timestamp in microseconds
    // https://stackoverflow.com/questions/5833094/get-a-timestamp-in-c-in-microseconds
    timestamp = (long long)tv.tv_sec*1000000+tv.tv_usec;
    pageFault = pageMemoryIndex(page) == -1;
    printf("timestamp: %lld, page: %2d, pagefault: %d\n", timestamp, page, pageFault);
    if (pageFault)
      insert(page);
    pageFaultCount += (pageFault == 1);
  }
  fclose(fp);
  printf("total pagefaults: %d\n", pageFaultCount);
}

typedef struct map {
  int key, val;
} map;

map *age;

int initializeAge() {
  for (int i = 0; i < pageFrameSize; i++) {
    age[i] = (map) {-1, -1};
  }
}

int findLRU() {
  int index = 0;
  int maximum = age[index].val;
  // first fill unfilled memory
  for (int i = 0; i < pageFrameSize; i++) {
    // printf("(%d %d %d)", i, age[i].key, age[i].val);
    if (age[i].key == -1) {
      // printf("here");
      return i;
    }
  }

  // give the least recently used index, (most aged)
  for (int i = 0; i < pageFrameSize; i++) {
    if (age[i].val > maximum) {
      maximum = age[i].val;
      index = i;
    }
  }
  return index;
}

int insertLRU(int page, int index) {
  int temp, current;

  temp = memory[index];
  memory[index] = page;
  current = temp;

  // maintaining the recently exited pages out of memory as directed in the
  // question
  for (int i = pageFrameSize; i < pageFrameSize; i++) {
    temp = memory[i];
    memory[i] = current;
    current = temp;
  }

  age[index] = (map) {page, 0}; // frequency of incoming page is 0, incrementAge
                               // makes it 1, which is currect Age.

  return 0;
}

int incrementAge() {
  for (int i = 0; i < pageFrameSize; i++) {
    if (age[i].key != -1) { // if there is actual page in memory
      age[i].val++;         // increment the age
    }
  }
  return 0;
}

int resetAge(int page) {
  for (int i = 0; i < pageFrameSize; i++) {
    if (age[i].key == page) {
      age[i].val = 0;
      return 0;
    }
  }

  // if control reaches here, there is a problem
  return 1;
}

void LRU() {
  initializeAge();
  int page;
  int pageFault = 0;
  int index;
  int pageFaultCount = 0;

  // Read File
  FILE *fp = fopen("mamtorah_proj2_input.txt", "r");

  if (fp == NULL) {
    perror("Unable to open the file");
    exit(1);
  }

  int input[INPUT_SIZE];
  int x;
  int i = 0;
  while (fscanf(fp, "%d", &page) == 1) {  
    gettimeofday(&tv,NULL);
    // timestamp in microseconds
    // https://stackoverflow.com/questions/5833094/get-a-timestamp-in-c-in-microseconds
    timestamp = (long long)tv.tv_sec*1000000+tv.tv_usec;
    pageFault = pageMemoryIndex(page) == -1;
    if (pageFault) {
      index = findLRU();
      insertLRU(page, index);
    } else {
      resetAge(page);
    }
    incrementAge();
    printf("timestamp: %lld, page: %2d, pagefault: %d\n", timestamp, page, pageFault);
    pageFaultCount += (pageFault == 1);
  }
  fclose(fp);
  printf("total pagefaults: %d\n", pageFaultCount);
}

typedef struct frame {
  int page, secondChanceBit;
} frame;

frame *memoryFrames;

void initializeSecondChance() {
  for (int i = 0; i < pageFrameSize; i++) {
    memoryFrames[i] = (frame) {-1, 0};
  }
}

int insertSecondChance(int page) {
  for (int i = 0; i < pageFrameSize; i++) {
      if (memoryFrames[i].page == page) {
        memoryFrames[i].secondChanceBit = 1;
        return 0; // no pageFault
      }
  }

  int outIndex = -1;

  // lets see if we find empty page
  for (int i = 0; i < pageFrameSize; i++) {
    if (memoryFrames[i].page == -1) {
      outIndex = i;
      break;
    }
  }

  if (outIndex != -1) {
    for (int i = outIndex; i > 0; i --) {
      memoryFrames[i] = memoryFrames[i-1];
    }
    memoryFrames[0] = (frame){page, 0};
    return 1;
  }

  // if control reaches here, this means, there's page fault, and we need to
  // check second chance bit too.

  // but first lets move the last 4 exited pages
  for (int i = pageFrameSize - 1; i > pageFrameSize; i--) {
    memoryFrames[i] = memoryFrames[i-1];
  }

  for (int i = pageFrameSize - 1; i >= 0; i--) {
    if (memoryFrames[i].secondChanceBit == 1) {
      memoryFrames[i].secondChanceBit = 0; // 2nd chance exhausted
    }
    else{
      // currently at an index to be moved out.
      memoryFrames[pageFrameSize] = memoryFrames[i]; // moved out
      outIndex = i;
      break;
    }
  }

  if (outIndex == -1) {
    // this means, all pageFrames got a second chance.
    // hence, outIndex should be the first page in. (since FIFO) 
    // first page in, would be at index pageFrameSize - 1
    outIndex = pageFrameSize - 1;
  }

  for (int i = outIndex; i > 0; i--) {
    memoryFrames[i] = memoryFrames[i-1];
  }

  // finally, we place the current page
  memoryFrames[0] = (frame){page, 0};
  return 1; // page fault had occured
}

void secondChance() {
  initializeSecondChance();
  int page;
  int pageFault = 0;
  int index = -1;
  int pageFaultCount = 0;

  // Read File
  FILE *fp = fopen("mamtorah_proj2_input.txt", "r");

  if (fp == NULL) {
    perror("Unable to open the file");
    exit(1);
  }

  // int input[INPUT_SIZE];
  // int x;
  // int i = 0;
  while (fscanf(fp, "%d", &page) == 1) {
    gettimeofday(&tv,NULL);
    // timestamp in microseconds
    // https://stackoverflow.com/questions/5833094/get-a-timestamp-in-c-in-microseconds
    timestamp = (long long)tv.tv_sec*1000000+tv.tv_usec;
    pageFault = insertSecondChance(page);
    for (int i = 0; i < pageFrameSize; i++){
      memory[i] = memoryFrames[i].page;
    }
    printf("timestamp: %lld, page: %2d, pagefault: %d\n", timestamp, page, pageFault);
    pageFaultCount += (pageFault == 1);
  }
  fclose(fp);
  printf("total pagefaults: %d\n", pageFaultCount);
}

int choosePageFrameSize() {
    int option;
    printf("Choose page frame size:\n");
    printf("Press 1 for 4-page frames\n");
    printf("Press 2 for 8-page frames\n");
    printf("Your choice: ");
    scanf("%d", &option);
    if(option == 1)
        return 4;
    else if (option == 2)
        return 8;

    printf("Please choose a valid option!\n");
    return -1;
}

int main() {
  int option;
  printf("Choose a page replacement algorithm:\n");
  printf("Press 1 for FIFO\n");
  printf("Press 2 for LRU\n");
  printf("Press 3 for Second Chance\n");
  printf("Your choice: ");
  scanf("%d", &option);

  pageFrameSize = choosePageFrameSize();


  if (pageFrameSize == -1)
    return 0;

  memory = (int*)malloc(pageFrameSize * sizeof(int));
  initializeMemory();

  switch (option) {
  case 1:
    printf("Running FIFO:\n");
    FIFO();
    break;
  case 2:
    printf("Running LRU:\n");
    age = (map*)malloc(pageFrameSize * sizeof(map));
    LRU();
    free(age);
    break;
  case 3:
    printf("Running Second Chance:\n");
    memoryFrames = (frame*)malloc(pageFrameSize * sizeof(frame));
    secondChance();
    free(memoryFrames);
    break;
  default:
    printf("Please choose a valid option!\n");
    break;
  }

  free(memory);
  return 0;
}