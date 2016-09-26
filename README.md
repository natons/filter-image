# EP1 - OO (UnB - Gama)

Este projeto consiste em um programa em C++ capaz de aplicar filtros em imagens de formato `.ppm`.

* 1 - Abra a imagem no formato PPM
* 2 - Leia o conteúdo da imagem
* 3 - Aplique o filtro na imagem
* 4 - Salve o conteúdo em outro arquivo

* Mais detalhes na wiki [home](https://gitlab.com/OOFGA-2016-1/EP1/wikis/home)

### Como Compilar e Executar

Para compilar e executar o programa em um sistema operacional Linux, siga as seguintes instruções:

* Abra o terminal;
* Encontre o diretório raiz do projeto;
* Limpe os arquivos objeto:
	**$ make clean** 
* Compile o programa: 
	**$ make**
* Execute:
	**$ make run**


### Entradas do usuário

As entradas referentes aos nomes das imagems (imagem para leitura e imagem para escrita), podem ou não serem acompanhadas de suas extensões. Fica a cargo do usuário. Entretanto não deve ser inserido o diretório da imagem (tanto na entrada quanto na saída), pois este foi definido de forma padrão, logo abaixo.

### Onde se localiza as imagens para leitura e escrita

Para o funcionamento correto do software é necessário que as imagens .ppm estejam localizadas na pasta "doc/", bem como a criação da nova imagem também estará armazenada neste diretório.
