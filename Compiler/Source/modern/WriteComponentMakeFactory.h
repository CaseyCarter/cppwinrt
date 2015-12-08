if (0 == wcscmp(expected, impl::traits<%::%>::name()))
        {
            *factory = detach(make<%Factory>());
        }
        else 