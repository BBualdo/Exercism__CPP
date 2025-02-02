namespace hellmath {

enum class AccountStatus
{
    troll,
    guest,
    user,
    mod
};

enum class Action
{
    read,
    write,
    remove
};

bool display_post(AccountStatus poster_status, AccountStatus viewer_status)
{
    if (poster_status == AccountStatus::troll)
    {
        if (viewer_status == AccountStatus::troll) return true;
        return false;
    }

    return true;
}

bool permission_check(Action action_type, AccountStatus account_status)
{
    switch (account_status)
    {
    case AccountStatus::mod:
        return action_type == Action::read || action_type == Action::write || action_type == Action::remove;
    case AccountStatus::user:
    case AccountStatus::troll:
        return action_type == Action::read || action_type == Action::write;
    case AccountStatus::guest:
        return action_type == Action::read;
    default:
        return false;
    }
}

bool valid_player_combination(AccountStatus account_1, AccountStatus account_2)
{
    if (account_1 == AccountStatus::guest || account_2 == AccountStatus::guest) return false;
    if ((account_1 == AccountStatus::troll && account_2 != AccountStatus::troll) || (account_1 != AccountStatus::troll && account_2 == AccountStatus::troll)) return false;
    return true;
}

bool has_priority(AccountStatus account_1, AccountStatus account_2)
{
    return static_cast<int>(account_1) > static_cast<int>(account_2);
}

}  // namespace hellmath