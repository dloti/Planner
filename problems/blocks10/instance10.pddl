

(define (problem BW-rand-10)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 b10 )
(:init
(arm-empty)
(on b1 b4)
(on-table b2)
(on-table b3)
(on b4 b9)
(on b5 b1)
(on-table b6)
(on b7 b8)
(on b8 b2)
(on b9 b6)
(on b10 b5)
(clear b3)
(clear b7)
(clear b10)
)
(:goal
(and
(on b1 b4)
(on b3 b10)
(on b5 b1)
(on b6 b2)
(on b7 b3)
(on b8 b9)
(on b10 b6))
)
)


