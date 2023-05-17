{-------------------------------------
 Resolução da lista 1
 Lucas Pessoa Oliveira Alves
--------------------------------------}

module Lista where
import Data.Char

{- Cabeçalho
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
ex: map reverse ["abc","qwr"] = ["cba","rwq"] (resolve o reverse para cada elemento da lista)

digitToInt -> faz a conversão de um char para int
ex: digitToInt 'F' = 15
    digitToInt '3' = 3

read -> converte strings para outro tipo (REDUZINDO)
ex: read "12" :: Int = 12
    read (reverse (show 12)) :: Int = 21

isAlpha -> compara o parametro passado para ver se faz parte do alfabeto retornando True/False
ex: isAlpha 'A' = True
    isAlpha '1' = False
-}

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

--Exercício 7 
escolha :: Int -> Int -> Int
escolha m n = (fat m) `div` ((fat n) * (fat(m-n)))

--Exercício 8
mdc :: Int -> Int -> Int
mdc m n
    | m `mod` n /= 0 = mdc n (m `mod` n)
    | otherwise = n

--Exercício 9
howManyMultiples :: Int -> Int -> Int -> Int
howManyMultiples x y z
    | x * y <= z && y <= z = 1 + howManyMultiples x (y+1) z
    | y <= z = howManyMultiples x (y+1) z
    | otherwise = 0

--Exercício 10
lastDigit :: Int -> Int
lastDigit x = x `mod` 10

--Exercício 11

anyDigit :: Int -> Int -> Int
anyDigit x y 
    | length (show y) > x = digitToInt (show y !! x)
    | otherwise = -1

---------------------------------------------------------------------------
percorre :: Int -> String -> Int
percorre 0 (a:_) = digitToInt a 
percorre x (a:b) = percorre (x-1) b
percorre _ _ = -1

anyDigit2 :: Int -> Int -> Int
anyDigit2 x y = percorre x (show y)
---------------------------------------------------------------------------

--Exercício 12
-- a) A definição proposta pelo programador está errada pois não um teste para 
-- saber se m é diferente de p.
-- b)
allDiferent m n p = (m /= n) && (n /= p) && (m /= p)
allDiferent :: Int -> Int -> Int -> Bool

--Exercício 13
howManyEqual :: Int -> Int -> Int -> Int
howManyEqual x y z
    | x == y && x == z = 3
    | x == y || x == z || y == z = 2
    | otherwise = 0

--Exercício 14
sales :: Int -> Int
sales 0 = 10
sales 1 = 45
sales 2 = 0
sales 3 = 23
sales 4 = 76
sales 5 = 63
sales 6 = 0

howManyLess :: Int -> Int -> Int -> Int
howManyLess value intervalBeginning intervalEnding
    | intervalBeginning /= intervalEnding && value > sales intervalBeginning = 1 + howManyLess value (intervalBeginning+1) intervalEnding
    | intervalBeginning /= intervalEnding && value < sales intervalBeginning = howManyLess value (intervalBeginning+1) intervalEnding
    | otherwise = 0

noZeroInPeriod :: Int -> Bool
noZeroInPeriod x = not (zeroInPeriod x)
{-
    | x /= 6 && sales x /= 0 = noZeroInPeriod(x+1)
    | sales x /= 0 = True
    | otherwise = False
    -}

isZeroDay :: Int -> Bool
isZeroDay x = sales x == 0

zeroInPeriod :: Int -> Bool
zeroInPeriod x
  | x < 0 = False
  | isZeroDay(x) = True
  | otherwise = zeroInPeriod(x-1)

--Exercício 15

fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib x = fib (x-1) + fib (x-2)

antFibAux :: Int -> Int -> Int
antFibAux num index
    | fib index == num = index+1
    | fib index >= num = -1
    | otherwise = antFibAux num (index+1)

antFib :: Int -> Int
antFib x = antFibAux x 0

--Exercício 16

funny :: Int -> Int -> Int -> Bool
funny x y _ = y < x

--Exercício 17

maiuscula :: Char->Char
maiuscula x = toUpper x 


--Exercício 18 
charToNum :: Char->Int
charToNum x
    | isDigit x = digitToInt x
    | otherwise = (-1)

--Exercício 19

duplicate :: String -> Int -> String
duplicate _ 0 = ""
duplicate s n = (duplicate s (n-1)) ++ s

--Exercício 20

pushRightConc :: Int -> String
pushRightConc x 
    | x /= 0 = pushRightConc (x-1) ++ ">"
    | otherwise = ""

pushRight :: String -> Int -> String
pushRight string tamanho
    | (length string) - tamanho < 0 =  (pushRightConc (tamanho - (length string))) ++ string
    | otherwise = string

{- Exercício 21
-> operador binário de nome &- com a semântica: x &- y = x - 2*y
10 &- 3 &- 2
a) operador definido como infixl 6 &-
(10 - 2*3) - 2*2 = 0
o resultado é 0 pois a precedência é da esquerda para a direita
10 - 2*(3 - 2*2) = 12
o resultado é 12 pois a precedência é da direita para a esquerda

c) operador definido como infix 6 &-
10 - 2*3 - 2*2 = erro
pois a precedência não tem definição de direita ou esquerda, então a função não tem pra onde ir

->operador binário de nome &- com a semântica: x &- y = x - 2*y
10 &- 3 * 2

a) 10 - ((2*3) * 2) = -2
é possível resolver tendo a multiplicação com maior precedência que a operção definida

b) (10 - 2*3) *2
a resolução é feita pela operação antes da multiplicação
-}
infix 6 &-
(&-) :: Int -> Int -> Int
x &- y = x - 2*y

--Exercício 22
inverte :: [Int] -> [Int]
inverte [] = []
inverte (a:b) = inverte b ++ [a]

inverte2 x = reverse x

--Exercício 23

separaImpar :: [Int] -> [Int]
separaImpar [] = []
separaImpar (a:b)
    | a `mod` 2 /= 0 = a : separaImpar b
    | otherwise = separaImpar b

separaPar :: [Int] -> [Int]
separaPar [] = []
separaPar (a:b)
    | a `mod` 2 == 0 = a : separaPar b
    | otherwise = separaPar b


separa :: [Int] -> ([Int],[Int])
separa [] = ([],[])
separa x = (separaImpar x, separaPar x)

--Exercício 24
converteAlf :: [Int] -> String
converteAlf [] = ""
converteAlf (a:b) = [(chr (a+64))] ++ converteAlf b

--Exercício 25
{-
(a) ['a'..'g'] =['a','b','c','d','e','f','g']
(b) [0.1 ..0.9] = [0.1,0.9] (pelo hugs [0.1,1.1])
(c) [0.1,0.3 .. 0.9] = [0.1,0.3,0.5,0.7,0.9]
(d) [0.1,0.3 ..1.8] = [0.1,0.3,0.5,0.7,0.9,1.1,1.3,1.5,1.7,1.9]
(e) [0.4,0.2 ..0.8] = []
(f) [1,4..15] = [1,4,7,10,13] (pelo menos [1,4,7,10,13,16])
-}

--Exercício 26
conta :: String -> String -> Int
conta [] _ = 0
conta (a:b)(c:_)
    | a == c = 1 + conta b [c]
    | otherwise = conta b [c]

--Exercício 27
inside :: [Int] -> Int -> Bool
inside [] _ = False
inside (a:b) c
    | a == c = True
    | otherwise = inside b c

purifica :: [Int] -> [Int]
purifica [] = []
purifica (a:b)
    | (inside b a) = purifica b
    | otherwise = a : purifica b

--Exercício 28
copy_and_paste_Int :: Int -> Int -> [Int] -> [Int]
copy_and_paste_Int x y z 
    | x < y = (copy_and_paste_Int (x+1) y z) ++ [y]
    | otherwise = []

proliferaInt :: [Int] -> [Int]
proliferaInt [] = []
proliferaInt (a:b) = copy_and_paste_Int 0 a [] ++ proliferaInt b

--Exercício 29
copy_and_paste_Char :: Int -> Char -> [Char] -> [Char]
copy_and_paste_Char x y z 
    | x < (ord y-64) = (copy_and_paste_Char (x+1) y z) ++ [y]
    | otherwise = []

proliferaChar :: [Char] -> String
proliferaChar [] = []
proliferaChar (a:b) = copy_and_paste_Char 0 a [] ++ proliferaChar b