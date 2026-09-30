#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std;

const int total_pixels = 1000;

void fill(string pixels[]){
for (int i = 0; i < total_pixels; i++){
pixels[i] = "#";
	}
}

void printloop(string pixels[]){

system("clear");

int margin = 0;

for (int i = 0; i < total_pixels; i++){

margin++;
cout << pixels[i];

if(margin == 50){

cout << endl;
margin = 0;

	}
}
}

int main(){

int contador = 0;

string pixels[total_pixels];

fill(pixels);

while (true) {
auto start = std::chrono::steady_clock::now(); // Start timer

string aux = pixels[contador];

pixels[contador] = "\033[30m#\033[0m";

//\033[38;2;0;0;0m

printloop(pixels);

pixels[contador] = "#";

contador++;

if(contador >= 999){

contador = 0;

}

auto end = std::chrono::steady_clock::now(); // End timer

std::chrono::duration<double> elapsed_seconds = end - start;

if(elapsed_seconds.count() < 0.016){
	std::this_thread::sleep_for(std::chrono::duration<double>(0.016 - elapsed_seconds.count()));

}
}
return 0;
}
