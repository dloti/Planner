

(define (problem BW-rand-10)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 b10 )
(:init
(arm-empty)
(on b1 b6)
(on b2 b4)
(on b3 b7)
(on-table b4)
(on-table b5)
(on-table b6)
(on b7 b2)
(on b8 b3)
(on b9 b1)
(on b10 b9)
(clear b5)
(clear b8)
(clear b10)
)
(:goal
(and
(on b1 b4)
(on b2 b1)
(on b3 b8)
(on b4 b6)
(on b6 b9)
(on b7 b10)
(on b8 b5)
(on b9 b7))
)
)


