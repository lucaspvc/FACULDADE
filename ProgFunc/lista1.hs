----------------------------------------------------
-- Resolução da lista 1
-- Lucas Pessoa Oliveira Alves
----------------------------------------------------
module Lista where
-- Exercício 1

f1::Float->Float
f1 x
    |x>=0 = (x+4)/(x+2)
    |otherwise = 2/x

f2::Int->Int->Int
f2 x y
    |x>=y = x+y
    |otherwise = x-y

f3::Int->Int->Int->Int
f3 x y z
    |(x+y)>z = x+y+z
    |(x+y)<z = x-y-z
    |otherwise = 0

-- Exercício 2
-- O erro da função está em não colocar um ponto de parada para a recursividade
fat::Int->Int
fat 0 = 1
fat x = x * fat(x-1)

-- Exercício 3
soma::Int->Int->Int
soma x y = x+y

mult::Int->Int->Int
mult x 1 = x
mult x y = soma x (mult x (y-1))


-- Exercício 4
invertInt :: Int -> Int
invertInt x = multL (intLista x) [1,10,100,1000,10000,100000,1000000,10000000]
  
intLista :: Int -> [Int]
intLista 0 = []
intLista x = intLista(div x 10) ++ [mod x 10]

multL::[Int] -> [Int] -> Int
multL [] _ = 0
multL _ [] = 0
multL (a:b) (c:d) = (a*c) + multL b d

-- Exercício 5
square :: Int -> Int
square x = x * x

fourPower::Int->Int
fourPower x = square(square x)

-- Exercício 6
sqr6::Float->Float
sqr6 1 = sqrt 6
sqr6 x = sqrt(6 + sqr6(x-1))

-- Exercício 7
    