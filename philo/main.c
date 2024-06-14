/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:09:17 by yasmine           #+#    #+#             */
/*   Updated: 2024/06/14 15:44:56 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (error_args(argc, argv, &table) == FALSE)
		return (1);
	if (create_philos(&table) == FALSE)
		return (1);
	if (create_forks(&table) == FALSE)
		return (1);
	if (table.args.nbr_philo == 1)
	{
		if (just_one_philo(&table) == FALSE)
			return (1);
		return (0);
	}
	if (create_threads(&table) == FALSE)
		return (1);
	if (destroy_threads(&table) == FALSE)
		return (1);
	ft_free(&table);
	return (0);
}
/*/* TODO - definir args validos, philos e mesa ✅
* main -> checar, inicializar e limpar ✅
* rotina -> comer, dormir e pensar ✅
* philo -> criar e preencher com os dados ✅
* action -> fazer as acoes acontecerem  ✅
* threads(filosofos) e mutex(garfos)  ✅

// Início do programa
main(argv):
    // Validar e inicializar entrada
    se error_handling(argv) == FALSO:
        imprimir "Erro: argumentos inválidos"
        retornar

    // Inicializar mesa, filósofos e garfos
    mesa = inicializar_estrutura_mesa(argv)

    // Criar threads de filósofos e garçom
    create_threads(mesa)

    // Aguardar conclusão das threads
    join_threads(mesa)

    // Destruir mutexes e liberar recursos
    destroy_threads(mesa)

// Definição da rotina do filósofo
função rotina(filósofo):
    enquanto TRUE:
        philo_eat(mesa, filósofo.id)
        philo_sleep(mesa, filósofo.id)
        philo_think(mesa, filósofo.id)

// Definição da rotina do verificador (checker)
função checker(mesa):
enquanto TRUE:
para cada filósofo em mesa:
    se a dif_tempo(filósofo.tempo_último_comer) > mesa.args.tempo_para_morrer:
    	mesa.filósofo_morto = VERDADE
		
// Execução das ações dos filósofos
função philo_eat(mesa, id):
    pegar garfos esquerdo e direito
    atualizar estado para "comendo"
    exec_action(mesa.args.tempo_para_comer)
    soltar garfos

função philo_sleep(mesa, id):
    atualizar estado para "dormindo"
    exec_action(mesa.args.tempo_para_dormir)

função philo_think(mesa, id):
    atualizar estado para "pensando"
*/
