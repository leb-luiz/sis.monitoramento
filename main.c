
#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Nome: Luiz Eduardo Batista
// Curso: Cibersegurança



void batimentos(void *pvParameters);
void oxigenio(void* pvParameters);
void temperatura(void* pvParameters);




//Batimentos
void batimentos(void *pvParameters)
{


	for (;; )
	{
		//rand para aleatoriar os valores
		int k = 20 + rand() % 120;
		vPrintStringAndNumber("Os batimentos estao em: ", k);
		
		if (k < 50) {
			printf("AVISO : OS BATIMENTOS ESTAO BAIXOS !\n");
		}
		else if (k > 90) {
			printf("AVISO: OS BATIMENTOS ESTAO MUITO ALTOS\n");
		}
		vTaskDelay(1000);
		
	}

	// Quando uma tarefa não for mais necessária, ela deverá ser excluída explicitamente.
	vTaskDelete(NULL);
}

//Oxigenio
void oxigenio(void* pvParameters) {
	for (;; )
	{
		//rand para aleatoriar os valores
		int j = 80 + rand() % 20;
		vPrintStringAndNumber("A oxigenacao esta em: ", j);

		if (j < 90) {
			printf("AVISO: SATURACAO BAIXA !\n");
		}
		vTaskDelay(1000);

	}

	// Quando uma tarefa não for mais necessária, ela deverá ser excluída explicitamente.
	vTaskDelete(NULL);
}

//Temperatura
void temperatura(void *pvParameters) {

	for (;; )
	{
		//rand para aleatoriar os valores
		int g = 34 + rand() % 7;
		vPrintStringAndNumber("A temperatura esta em: ", g);

		if (g < 35) {
			printf("AVISO: HIPOTERMIA !\n");
		}
		else if(g > 37.5){
			printf("AVISO: FEBRE !\n");
		}
		vTaskDelay(1000);

	}

	// Quando uma tarefa não for mais necessária, ela deverá ser excluída explicitamente.
	vTaskDelete(NULL);
}

int main_(void)
{	
	srand(time(NULL));
	//Cria as Tasks
	xTaskCreate(batimentos, "Task Batimentos ", 1000, NULL, 1, NULL);
	xTaskCreate(oxigenio, "Task Oxigenacao", 1000, NULL, 1, NULL);
	xTaskCreate(temperatura, "Task Temperatura", 1000, NULL, 1, NULL);
	
	// Inicia o escalonador de tarefas
	vTaskStartScheduler();

	for (;; );
	return 0;
}
