Serão 7 mini projetos que ao longo do semestre irão se complementar ate o sétimo onde será uma "versão final"

1) a) Implementar a lista de objetos virtuais (Display File) para pontos, retas e polıgonos;
b) Visualizar os objetos do display file na interface do usuario; 
c) No display file, os objetos devem ser representados em coordenadas de mundo e nao coordenadas de tela; 
d) Cada objeto precisa ter em sua representacao: nome, tipo e lista de pontos;
OBS.: Um mundo limitado ao tamanho da area de desenho da interface. Assim coordenadas de mundo e de
desenho serao coincidentes.

2)  devera implementar as transformacoes geometricas:
a) Translacao de objetos da cena;
b) Escala em torno do centro geometrico do objeto;
c) Rotacao em torno de um ponto escolhidopelo usuario (sistemas de coordenadas do mundo!);
OBS.1: As transformacoes aplicadas a um objeto nao podem afetar os demais. 
OBS.2: E preciso demonstrar o uso de composicao de matrizes. 
OBS.3: Nesse ponto ja da para perceber que usar as formas primitivas da biblioteca pode
nao ser a melhor escolha. Entao e melhor re-presentar seus objetos como listas de pontos e arestas.

3) a) Implementar a window com coordenadas normalizadas. Modo mais pratico: dobrar as coordenadas dos objetos no display file;
b) Acrescente algum mecanismo para modificar os parametros da window para ver o efeito na area de desenho. A cada mudanca o SCN precisa ser recalculado;
c) Acrescente algum mecanismo para modificar os parametros da viewport para ver o efeito na area de desenho. A cada mudanca, a transformada de viewport precisa ser recalculada;

4) a) Implementar o clipping 2D em seu sistema de visualizacao; 
b) Na area de desenho, desenhe uma moldura interna para representar sua viewport. O desenho do conteudo da window deve estar limitado a esta moldura. A parte entre a moldura e o limite da area de desenho precisa estar limpa;
c) Modifique a window usando as transformac¸oes geometricas para ver o efeito em sua area de desenho. Use para isso, as operacoes de Rotacao, Translacao e Escala.

5) a) Incluir a leitura de arquivo do tipo OBJ1.
b) Escolha pelo menos dois pokemons diferentes para visualizar em seu projeto. Exemplos de modelos podem ser encontrados acessando: https://free3d.com/3dmodel/charizard-85299.html
1. Uma boa documentacao pode ser encontrada em [5].
c) Os pokemons devem ser inseridos nacena que voce ja criou nas outras entregas e visualizados ao mesmo tempo.
d) Ajustar as transformacoes geometricas para 3D;
e) Incluir a projecao ortogonal ao projeto de visualizacao;
6) Na entrega 06 o aluno devera incluir a projecao perspectiva ao projeto;

7) a) Fazer os arremates finais para a entrega do projeto;
b) incluir na interface algum mecanismo para as transformacoes no objeto e navegacao de camera;
