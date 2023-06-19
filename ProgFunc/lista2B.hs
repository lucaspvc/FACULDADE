{-------------------------------------
 Resolução da lista 2-B
 Lucas Pessoa Oliveira Alves
--------------------------------------}

module Lista where
import Data.Char
{- Cabeçalho
minimun -> Retorna o menor valor Int de uma lista
ex: minimun [5,2,6,1,6,7,4] = 1

maximun -> Retorna o maior valor Int de uma lista
ex: maximun [5,1,6,4,3,9,5,6] = 9

min -> retorna o menor valor entre 2 argumentos
ex: min 1 7 = 1

max -> retorna o maior valor entre 2 argumentos
ex: max 8 14 = 14

where -> É uma palavra-chave usada para dividir a lógica ou cálculo mais complexo 
em partes menores, o que torna a lógica ou o cálculo fácil de entender e manusear

show y -> Resulta em uma string do conteúdo de y
ex: show 123 = "123"
    show 'a' = "a"

length y -> se y for uma string ou lista, retorna o comprimento da string, caso contrário, é preciso transformar para string
ex: length "11111" = 5
    length (show 444) = 3 (show transforma o int em string e length mede o comprimento)
    length [1,2,3,2,1] = 5
    
toUpper -> tranforma o char de minúsculo para maiúsculo, se não for uma letra retorna a entrada
ex: toUpper 'x' = 'X'
    toUpper '1' = '1'
    toUpper '!' = '!'

toLower -> transforma o char de maiúsculo para minúsculo, se não for uma letra retorna a entrada
ex: toLower 'X' = 'x'
    toLower '1' = '1'

ord -> retorna o código ASCII
ex: ord 't' = 116
    ord 'A' = 65

chr -> retorna o correspondente ao seu código da tabela ASCII
ex: chr 65 = 'A'
    chr 97 = 'a'

reverse -> cria uma nova string com os itens na ordem reversa
ex: reverse "abc" = "cba"

map -> entra em cada elemento de uma lista 
ex: map reverse ["abc","qwr"] = ["cba","rwq"] (resolve o reverse para cada elemento da lista)t

digitToInt -> faz a conversão de um char para int
ex: digitToInt 'F' = 15
    digitToInt '3' = 3

read -> converte strings para outro tipo (REDUZINDO)
ex: read "12" :: Int = 12
    read (reverse (show 12)) :: Int = 21

isAlpha -> compara o parametro passado para ver se faz parte do alfabeto retornando True/False
ex: isAlpha 'A' = True
    isAlpha '1' = False

isDigit -> compara o parametro passado para ver se é um digito
ex: isDigit 1 = True
    isDigit 'M' = False

sum -> faz a somatória do que está sendo passada

odd -> Retorna true se o valor passado for ímpar, false caso contrário
ex: odd 7 = True
    odd 8 = False
-}

--Exercício 1
ex1::Integer
ex1 = sum [x^2| x <- [100,99..0]]

--Exercício 2
ex2::Int-> a-> [a]
ex2 x y = [ y | _ <- [1..x]]

--Exercício 3
pyths :: Int -> [(Int, Int, Int)]
pyths a = [(x, y, z) | x <- [1..a], y <- [1..a], z <- [1..a], x^2 + y^2 == z^2]

--Exercício 4
perfects:: Int -> [Int]
perfects x = [x | x <- [1..x], sum [ a | a <- [1..x-1], x `mod` a == 0] == x]

--Exercício 5
ex5 :: [[(Int,Int)]]
ex5 = [[(x,y) | y <- [4,5,6]] | x <- [1,2,3]]

--Exercício 6
positions :: Eq a => a -> [a] -> [Int]
positions x xs = find x (zip xs [0..n])
    where n = (length xs) - 1

find :: Eq a => a -> [(a, Int)] ->[Int]
find x l = [ b | (a,b) <- l, x == a]

--Exercício 7
scalarproduct :: [Int] -> [Int] -> Int
scalarproduct a b = sum [x*y | (x,y)<- zip a b ]

--Exercício 8
infixr 8 &!
(&!):: Integer -> Int -> Integer
x &! 0 = 1
x &! y = x * (x &! (y-1)) 

--Exercício 9
--[f x | x <- xs, p x]
--[(+7) x | x <- [1..10],odd x]
ex9 f p xs = map f (filter p xs)

--Exercício 10
--dec2int :: [Int] -> Int

--Exercício 11
unfold :: (a -> Bool) -> (a -> b) -> (a -> a) -> a -> [b]
unfold p h t x
  | p x = []
  | otherwise = h x : unfold p h t (t x)