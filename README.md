## Como eu testei o código

coloquei no shell:
gcc CodFonte.c -o ex23

- ./ex23 dados.txt

depois disso deu o retorno:

Lido 7 nos do arquivo "dados.txt"

Depuração: percurso pre-ordem
123 123.50 Fulano da Silva
50 234.45 Beltrano
25 2304.23 Horarcio 
60 4000.45 Gervazio
300 345.46 Ciclano
250 3450.00 Antonela Fonseca
500 567.56 Jose Carlos

Depuração: percurso em em-ordem
25 2304.23 Horarcio 
50 234.45 Beltrano
60 4000.45 Gervazio
123 123.50 Fulano da Silva
250 3450.00 Antonela Fonseca
300 345.46 Ciclano
500 567.56 Jose Carlos

Depuração: percurso em pós-ordem
25 2304.23 Horarcio 
60 4000.45 Gervazio
50 234.45 Beltrano
250 3450.00 Antonela Fonseca
500 567.56 Jose Carlos
300 345.46 Ciclano
123 123.50 Fulano da Silva

Digite um valor a ser buscado:
60
Achei 60
60 4000.45 Gervazio
Digite um nome a ser encontrado:
Antonela
Antonela não encontrado na árvore
Total de salarios = R$ 11025.65

- ./ex23 completa.txt

Lido 7 nos do arquivo "completa.txt"

Depuração: percurso pre-ordem
123 123.50 Fulano da Silva
50 234.45 Beltrano
25 2304.23 Horarcio 
60 4000.45 Gervazio
300 345.46 Ciclano
250 3450.00 Antonela Fonseca
500 567.56 Jose Carlos

Depuração: percurso em em-ordem
25 2304.23 Horarcio 
50 234.45 Beltrano
60 4000.45 Gervazio
123 123.50 Fulano da Silva
250 3450.00 Antonela Fonseca
300 345.46 Ciclano
500 567.56 Jose Carlos

Depuração: percurso em pós-ordem
25 2304.23 Horarcio 
60 4000.45 Gervazio
50 234.45 Beltrano
250 3450.00 Antonela Fonseca
500 567.56 Jose Carlos
300 345.46 Ciclano
123 123.50 Fulano da Silva

Digite um valor a ser buscado:
60
Achei 60
60 4000.45 Gervazio
Digite um nome a ser encontrado:
Beltrano
Achei Beltrano
50 234.45 Beltrano
Total de salarios = R$ 11025.65

- ./ex23 zigazag.txt

Lido 7 nos do arquivo "zigazag.txt"

Depuração: percurso pre-ordem
25 2304.23 Horarcio 
50 234.45 Beltrano
60 4000.45 Gervazio
123 123.50 Fulano da Silva
250 3450.00 Antonela Fonseca
300 345.46 Ciclano
500 567.56 Jose Carlos

Depuração: percurso em em-ordem
25 2304.23 Horarcio 
50 234.45 Beltrano
60 4000.45 Gervazio
123 123.50 Fulano da Silva
250 3450.00 Antonela Fonseca
300 345.46 Ciclano
500 567.56 Jose Carlos

Depuração: percurso em pós-ordem
500 567.56 Jose Carlos
300 345.46 Ciclano
250 3450.00 Antonela Fonseca
123 123.50 Fulano da Silva
60 4000.45 Gervazio
50 234.45 Beltrano
25 2304.23 Horarcio 

Digite um valor a ser buscado:
25
Achei 25
25 2304.23 Horarcio 
Digite um nome a ser encontrado:
Fulano da Silva
Achei Fulano da Silva
123 123.50 Fulano da Silva
Total de salarios = R$ 11025.65
~/workspace$ ^C
