

(define (problem BW-rand-9)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 )
(:init
(arm-empty)
(on-table b1)
(on-table b2)
(on-table b3)
(on b4 b7)
(on-table b5)
(on b6 b3)
(on b7 b2)
(on-table b8)
(on b9 b1)
(clear b4)
(clear b5)
(clear b6)
(clear b8)
(clear b9)
)
(:goal
(and
(on b2 b6)
(on b3 b1)
(on b5 b4)
(on b6 b9)
(on b7 b3)
(on b9 b8))
)
)


