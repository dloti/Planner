

(define (problem BW-rand-9)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 )
(:init
(arm-empty)
(on b1 b3)
(on b2 b7)
(on b3 b8)
(on b4 b2)
(on-table b5)
(on-table b6)
(on-table b7)
(on b8 b4)
(on-table b9)
(clear b1)
(clear b5)
(clear b6)
(clear b9)
)
(:goal
(and
(on b2 b1)
(on b3 b6)
(on b4 b3)
(on b7 b8)
(on b9 b2))
)
)


