

(define (problem BW-rand-20)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 b10 b11 b12 b13 b14 b15 b16 b17 b18 b19 b20 )
(:init
(arm-empty)
(on b1 b14)
(on b2 b18)
(on b3 b16)
(on-table b4)
(on b5 b2)
(on-table b6)
(on b7 b9)
(on b8 b13)
(on b9 b4)
(on b10 b11)
(on-table b11)
(on b12 b7)
(on-table b13)
(on b14 b10)
(on-table b15)
(on b16 b8)
(on b17 b12)
(on b18 b3)
(on b19 b5)
(on-table b20)
(clear b1)
(clear b6)
(clear b15)
(clear b17)
(clear b19)
(clear b20)
)
(:goal
(and
(on b1 b9)
(on b2 b20)
(on b3 b1)
(on b4 b18)
(on b7 b19)
(on b8 b5)
(on b9 b12)
(on b10 b11)
(on b11 b4)
(on b12 b2)
(on b13 b7)
(on b14 b17)
(on b15 b10)
(on b16 b13)
(on b17 b6)
(on b18 b16)
(on b19 b3)
(on b20 b14))
)
)

