----------------------------------------------------
-- Exercício feito em sala
-- Lucas Pessoa Oliveira Alves
----------------------------------------------------

periodo :: Int
periodo = 7


-- tabela de vendas
vendas :: Int -> Int
vendas 0 = 0
vendas 1 = 93
vendas 2 = 72
vendas 3 = 48
vendas 4 = 0
vendas 5 = 93
vendas 6 = 55
vendas 7 = 30

-- função auxiliar maior

maior::Int->Int->Int
maior a b
  | (a>b) = a
  | otherwise = b

-- retorna maior venda

maiorVenda :: Int-> Int
maiorVenda x
   | x==0 = vendas 0
   | otherwise = maior (vendas x) (maiorVenda(x-1))


--Função que retonra uma lista dos dias de maiores vendas
--Passa como parâmetro no terminal (periodo) e (maioVenda periodo)

listaMaiorVenda::Int->Int->[Int]
listaMaiorVenda (-1) _ = []
listaMaiorVenda d mV
    |vendas d == mV = d:listaMaiorVenda (d-1) mV
    |otherwise = listaMaiorVenda(d-1) mV


listaVendas::Int->[[Int]]
listaVendas 0 = []
listaVendas d = [d,vendas d]:listaVendas (d-1)


listaTuplaVendas::Int->[(Int,Int)]
listaTuplaVendas 0 = []
listaTuplaVendas d = (d,vendas d):listaTuplaVendas (d-1)


maiovenda1::[(Int,Int)]->Int->Int
maiovenda1 [] m = m
maiovenda1 ((_,b):x) m
    |b >= m = maiovenda1 x b
    |otherwise = maiovenda1 x m