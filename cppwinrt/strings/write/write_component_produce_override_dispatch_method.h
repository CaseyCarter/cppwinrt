    % %(%)
    {
        @ super = this->shim_super();
        if (super)
        {
            return super.%(%);
        }
        return this->shim().%(%);
    }
