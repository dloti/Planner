(define (problem BLOCKS-4-2)
(:domain BLOCKS)
(:objects B C A F G )
(:init (clear A) (clear C) (clear B) (clear F) (clear G) (on-table A) (on-table B) (on-table C) (on-table F) (on-table G) (arm-empty) )
(:goal (AND (on A B) (on B C) (on C F) (on F G)))
)
