#include "libft.h"

int		opt_addvar2(t_opt **opt, char *arg, void **var, char type_var)
{
	t_opt *nopt;

	if (!(nopt = malloc(sizeof(t_opt))))
		return (1);
	ft_strcpy(nopt->opt, arg);
	nopt->var = NULL;
	nopt->var2 = var;
	nopt->type = OPT_VAR;
	nopt->type_var = type_var;
	nopt->next = *opt;
	*opt = nopt;
	return (0);
}

int		opt_addvar(t_opt **opt, char *arg, void *var, char type_var)
{
	t_opt *nopt;

	if (!(nopt = malloc(sizeof(t_opt))))
		return (1);
	ft_strcpy(nopt->opt, arg);
	nopt->var = var;
	nopt->var2 = NULL;
	nopt->type = OPT_VAR;
	nopt->type_var = type_var;
	nopt->next = *opt;
	*opt = nopt;
	return (0);
}

void	opt_init(t_opt **opt)
{
	*opt = NULL;
}

t_opt	*isoptin(t_opt *opt, char *arg)
{
	while (opt)
	{
		if (!ft_strcmp(arg, opt->opt))
			return (opt);
		opt = opt->next;
	}
	return (NULL);
}

int		opt_parseopt(t_opt *mopt, char ***argv, char *name)
{
	char **arg;

	arg = *argv;
	if (!arg[1])
	{
		ft_printf("%s: option requires an argument -- '%s'\n", name, arg[0]);
		return (OPT_MISSARG);
	}
	if (mopt->type_var == OPT_STR) {
		*mopt->var2 = arg[1];
	}
	else if (mopt->type_var == OPT_INT)
	{
		if (!ft_isint(arg[1]))
		{
			ft_printf("%s: invalid argument: '%s'\n", name, arg[1]);
			return (OPT_IVLARG);
		}
		*(int*)mopt->var = ft_atoi(arg[1]);
	}
	(*argv)++;
	return (OPT_OK);
}

void	opt_free(t_opt **opt)
{
	t_opt *nopt;

	nopt = *opt;
	while (*opt)
	{
		nopt = (*opt)->next;
		free(*opt);
		*opt = nopt;
	}
	*opt = NULL;
}

int		opt_parser(t_opt *opt, char **arg, t_optpars *optpars, char *name)
{
	t_opt	*mopt;
	char	end;
	int		ret;

	end = 0;
	optpars->arg = NULL;
	optpars->opt[0] = NULL;
	while (*arg)
	{
		if (!ft_strlen(*arg) || end) {
			optpars->arg = arg;
			return (0);
		}
		else if (!ft_strcmp(*arg, "--"))
			end = 1;
		else if (!ft_strncmp(*arg, "-", 1))
		{
			if ((mopt = isoptin(opt, *arg)))
			{
				ft_tabadd(optpars->opt, *arg);
				if (mopt->var || mopt->var2)
				{
					if ((ret = opt_parseopt(mopt, &arg, name)))
						return (ret);
				}
			}
			else
			{
				ft_printf("%s: invalid option -- '%s'\n", name, *arg);
				return (OPT_NFOUND);
			}
		}
		else {
			optpars->arg = arg;
			return (0);
		}
		arg++;
	}
	return (0);
}
