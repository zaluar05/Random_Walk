#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <random>
#include <vector>
#include <iostream>

void Imprime_agentes(std::vector<std::vector<std::pair<float, float>>>& posicoes, std::vector<std::vector<int>>& cores);
void Cores_Aleatorias(std::vector<std::vector<int>>& cores, int quantidade_agentes);
void le_quantidade_agentes(int &quantidade_agentes);

const int HEIGHT = 900;
const int WIDTH = 600;
const int BLOCK_SIZE = 5;
const int DISTANCE = 5;