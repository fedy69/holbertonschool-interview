#!/usr/bin/python3
"""checking all locked boxes"""


def canUnlockAll(boxes):
    """_summary_
    Args:
        boxes (_type_): list of lists to check
    Returns:
        _type_: _description_
    """
    canUnlockAll = False
    keys = {0: True}
    n_boxes = len(boxes)
    while (True):

        n_keys = len(keys)

        for i in range(len(boxes)):
            if boxes[i] and keys.get(i, False):
                for j in boxes[i]:
                    if j < n_boxes:
                        keys[j] = True
                    boxes[i] = None

        if not (len(keys) > n_keys):
            break

    if n_keys == len(boxes):
        canUnlockAll = True

    return canUnlockAll
