

(define (problem BW-rand-8)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 )
(:init
(arm-empty)
(on b1 b3)
(on b2 b7)
(on b3 b5)
(on b4 b6)
(on-table b5)
(on b6 b2)
(on b7 b8)
(on-table b8)
(clear b1)
(clear b4)
)
(:goal
(and
(on b3 b7)
(on b4 b6)
(on b5 b2)
(on b6 b1)
(on b8 b5))
)
)


