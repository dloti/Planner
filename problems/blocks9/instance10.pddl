

(define (problem BW-rand-9)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 )
(:init
(arm-empty)
(on-table b1)
(on b2 b4)
(on-table b3)
(on b4 b5)
(on b5 b1)
(on b6 b7)
(on-table b7)
(on b8 b6)
(on b9 b8)
(clear b2)
(clear b3)
(clear b9)
)
(:goal
(and
(on b1 b8)
(on b2 b1)
(on b4 b9)
(on b5 b2)
(on b6 b5)
(on b8 b3)
(on b9 b6))
)
)


