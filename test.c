#include <stdio.h>
#include "fml.h"
#include "mag.h"
#include "rld0.h"
#include "htab.h"

int main(int argc, char *argv[])
{
	int n_seqs;
	bseq1_t *seqs;
	fml_opt_t opt;
	int n_utg;
	fml_utg_t *utg;

	fml_opt_init(&opt);
	opt.bfc_opt.k = 17;
	if (argc == 1) return 1;
	seqs = bseq_read(argv[1], &n_seqs);
	/*
	struct rld_t *e;
	struct mag_t *g;
	fml_correct(&opt, n_seqs, seqs);
//	int i; for (i = 0; i < n_seqs; ++i) printf("@%s\n%s\n+\n%s\n", seqs[i].name, seqs[i].seq, seqs[i].qual);
	e = fml_seq2fmi(&opt, n_seqs, seqs);
//	rld_dump(e, "-");
	g = fml_fmi2mag(&opt, e);
	fml_mag_clean(&opt, g);
	mag_g_print(g);
	utg = fml_mag2utg(g, &n_utg);
	*/
	utg = fml_assemble(&opt, n_seqs, seqs, &n_utg);
	fml_utg_print(n_utg, utg);
	fml_utg_destroy(n_utg, utg);
	return 0;
}
