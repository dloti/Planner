

(define (problem BW-rand-9)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 )
(:init
(arm-empty)
(on-table b1)
(on b2 b6)
(on b3 b1)
(on b4 b8)
(on b5 b9)
(on-table b6)
(on b7 b2)
(on b8 b7)
(on-table b9)
(clear b3)
(clear b4)
(clear b5)
)
(:goal
(and
(on b1 b9)
(on b2 b4)
(on b4 b8)
(on b5 b6)
(on b7 b2)
(on b9 b5))
)
)


