from itertools import combinations


def rSubset(arr, r):
    # return list of all subsets of length r
    # to deal with duplicate subsets use
    # set(list(combinations(arr, r)))
    return list(combinations(arr, r))


def permutation(lst):
    # If lst is empty then there are no permutations
    if len(lst) == 0:
        return []

    # If there is only one element in lst then, only
    # one permutation is possible
    if len(lst) == 1:
        return [lst]

    # Find the permutations for lst if there are
    # more than 1 characters

    l = []  # empty list that will store current permutation

    # Iterate the input(lst) and calculate the permutation
    for i in range(len(lst)):
        m = lst[i]

        # Extract lst[i] or m from the list.  remLst is
        # remaining list
        remLst = list(lst[:i]) + list(lst[i + 1:])

        # Generating all permutations where m is first
        # element
        for p in permutation(remLst):
            l.append([m] + p)
    return l


def all_strategies(options, two_n):
    lst = []
    if two_n == 1:
        for option in options:
            lst.append([option])
        return lst
    pre_lst = all_strategies(options, two_n - 1)
    for option in options:
        for pre_opt in pre_lst:
            new_item = pre_opt.copy()
            new_item.append(option)
            lst.append(new_item)
            if len(lst) > 100000:
                break
        if len(lst) > 100000:
            break
    return lst


def choose_best_strategy(all_strategies, all_perms):
    strategy_holds_for_perms_count_max = 0
    best_strategy = 0
    for strategy in all_strategies:
        strategy_holds_for_perms_count = 0
        for perm in all_perms:
            strategy_holds = 1
            for i in range(len(perm)):
                if not (perm[i] in strategy[i]):
                    strategy_holds = 0
            if strategy_holds == 1:
                strategy_holds_for_perms_count += 1
        if strategy_holds_for_perms_count > strategy_holds_for_perms_count_max:
            strategy_holds_for_perms_count_max = strategy_holds_for_perms_count
            best_strategy = strategy
    print("best strategy : " + str(best_strategy))
    print("with success rate of : " + str(strategy_holds_for_perms_count_max) + " / " + str(len(all_perms)))


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    two_n_factor = 1
    for n in range(1, 4):
        two_n_factor = two_n_factor * (2 * n) * (2 * n - 1)

        print("n = " + str(n))
        print("number of people (2n): " + str(2*n))

        print("number of options for number distribution ((2n)!) : " + str(two_n_factor))
        all_number_list = list(range(1, 2 * n + 1))
        all_perms = permutation(all_number_list)
        #print("all number distribution options : " + str(all_perms))

        all_choose_options = rSubset(all_number_list, n)
        all_choose_options_len = len(all_choose_options)
        print("all options of number to choose for a prisoner (2n choose n) : " + str(all_choose_options_len))
        print("options for numbers to choose : " + str(all_choose_options))

        num_of_strategies = all_choose_options_len ** (2 * n)
        print("number of strategies possible ((2n choose n) ^ 2n) : " + str(num_of_strategies))
        all_strat = all_strategies(all_choose_options, 2 * n)
        #print("all strategies: " + str(all_strat))

        choose_best_strategy(all_strat, all_perms)

        print()
