import Data.Char

--Questão 1
--Poderia usar isDigit do Data.Char
--Faça a função func1 que receba uma string e retorne a quantidade de caracteres numéricos presentes na string
--func1 :: String -> Int

isDigit1::Char -> Bool
isDigit1 x = ('0' <= x) && (x <= '9')

func1::String -> Int
func1 [] = 0
func1 (a:b)
    | isDigit1 (a) = 1 + func1 (b)
    | otherwise = 0 + func1 (b)

--Questão 2
-- Faça a função func2 que receba duas strings e retorne a string com maior quantidade de carcateres numéricos. 
-- Caso a quantidade seja a mesma entre elas, qualquer uma poderá ser retornada. Use necessariamente, func1.

func2::String -> String -> String
func2 [] s = s 
func2 s [] = s 
--para esse problema a base é desnecessária
func2 a b 
    | func1 (a) > func1 (b) = a
    | otherwise = b 

--Questão 3
-- Faça  a função func3 de alta ordem, necessariamente com uso de list comprehension, que receba, além da função
-- parâmetro, um [(String, String)] e retorne [String] com as strings  com maior quantidade de caracteres 
-- numérico de cada dupla. Adote, como tipo do parâmetro da função recebida por func3, o tipo da função da 
-- questão anterior, func2.

func3:: (String -> String -> String) -> [(String, String)] -> [String]
func3 f x [f a b |(a,b) <-x ]
-- ou func3 f x [f (fst a) (snd a) | a <-x]

--Questão 4
-- Considere o código Haskell a seguir e responda
-- funT _ _ _ [] = []
-- funT p h t (a:x)
--    | t a = h (p a) : funT p h t x
--    | otherwise = funT p h t x 

-- possui a = snd (a)

-- muda a = reverse (fst (a))

-- limite [] = (0, [])
-- limite x = (length x, x)


--a) Apresente um cabeçalho para a função possui. Caso algum tipo não seja rígido, use o tipo genérico.

possui::([] ,Bool) -> Bool

--b) Apresente um cabeçalho para a função limite. Caso algum tipo não seja rígido, use o tipo genérico.

muda:: ([a], Bool ) -> [a]

--c) Apresente um cabeçalho para a função muda. Caso algum tipo não seja rígido, use o tipo genérico.

limite:: [a] -> (Int, [a])

--d) Faça uma chamada para a função funT passando adequadamente parâmetros a ela. No caso, como ela é de alta ordem,
-- você deverá usar apenas as funções já definidas no código apresentado nesta questão. Já o último parâmetro, você
-- deverá propô-lo. Contudo, não pode ser lista vazia.

funT muda limite possui [ ( [2,3], False ), ( [4, 5] , True) ]

--e) Para a chamada da função funT que você propôs no item anterior, informe qual será a saída que o programa apresentará.

resultado = [(2, [5, 4])]