

(define (problem BW-rand-8)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 )
(:init
(arm-empty)
(on b1 b6)
(on-table b2)
(on b3 b5)
(on b4 b1)
(on-table b5)
(on b6 b2)
(on-table b7)
(on b8 b7)
(clear b3)
(clear b4)
(clear b8)
)
(:goal
(and
(on b3 b4)
(on b4 b5)
(on b5 b2)
(on b6 b1)
(on b8 b3))
)
)


