/* We can't seem to route the following:
 *
 * Expect route 03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf -> 0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae -> 02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06
 *
 * getchannels:
 * {'channels': [{'active': True, 'short_id': '6990:2:1/1', 'fee_per_kw': 10, 'delay': 5, 'flags': 1, 'destination': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'source': '02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06', 'last_update': 1504064344}, {'active': True, 'short_id': '6989:2:1/0', 'fee_per_kw': 10, 'delay': 5, 'flags': 0, 'destination': '03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf', 'source': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'last_update': 1504064344}, {'active': True, 'short_id': '6990:2:1/0', 'fee_per_kw': 10, 'delay': 5, 'flags': 0, 'destination': '02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06', 'source': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'last_update': 1504064344}, {'active': True, 'short_id': '6989:2:1/1', 'fee_per_kw': 10, 'delay': 5, 'flags': 1, 'destination': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'source': '03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf', 'last_update': 1504064344}]}
 */
#include <common/status.h>

#include <stdio.h>
#define status_trace(fmt, ...) \
	do { printf((fmt) ,##__VA_ARGS__); printf("\n"); } while(0)

#include "../routing.c"

struct broadcast_state *new_broadcast_state(tal_t *ctx UNNEEDED)
{
	return NULL;
}

/* AUTOGENERATED MOCKS START */
/* Generated stub for fromwire_channel_announcement */
bool fromwire_channel_announcement(const tal_t *ctx UNNEEDED, const void *p UNNEEDED, size_t *plen UNNEEDED, secp256k1_ecdsa_signature *node_signature_1 UNNEEDED, secp256k1_ecdsa_signature *node_signature_2 UNNEEDED, secp256k1_ecdsa_signature *bitcoin_signature_1 UNNEEDED, secp256k1_ecdsa_signature *bitcoin_signature_2 UNNEEDED, u8 **features UNNEEDED, struct sha256_double *chain_hash UNNEEDED, struct short_channel_id *short_channel_id UNNEEDED, struct pubkey *node_id_1 UNNEEDED, struct pubkey *node_id_2 UNNEEDED, struct pubkey *bitcoin_key_1 UNNEEDED, struct pubkey *bitcoin_key_2 UNNEEDED)
{ fprintf(stderr, "fromwire_channel_announcement called!\n"); abort(); }
/* Generated stub for fromwire_channel_update */
bool fromwire_channel_update(const void *p UNNEEDED, size_t *plen UNNEEDED, secp256k1_ecdsa_signature *signature UNNEEDED, struct sha256_double *chain_hash UNNEEDED, struct short_channel_id *short_channel_id UNNEEDED, u32 *timestamp UNNEEDED, u16 *flags UNNEEDED, u16 *cltv_expiry_delta UNNEEDED, u64 *htlc_minimum_msat UNNEEDED, u32 *fee_base_msat UNNEEDED, u32 *fee_proportional_millionths UNNEEDED)
{ fprintf(stderr, "fromwire_channel_update called!\n"); abort(); }
/* Generated stub for fromwire_ipaddr */
bool fromwire_ipaddr(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, struct ipaddr *addr UNNEEDED)
{ fprintf(stderr, "fromwire_ipaddr called!\n"); abort(); }
/* Generated stub for fromwire_node_announcement */
bool fromwire_node_announcement(const tal_t *ctx UNNEEDED, const void *p UNNEEDED, size_t *plen UNNEEDED, secp256k1_ecdsa_signature *signature UNNEEDED, u8 **features UNNEEDED, u32 *timestamp UNNEEDED, struct pubkey *node_id UNNEEDED, u8 rgb_color[3] UNNEEDED, u8 alias[32] UNNEEDED, u8 **addresses UNNEEDED)
{ fprintf(stderr, "fromwire_node_announcement called!\n"); abort(); }
/* Generated stub for fromwire_u8 */
u8 fromwire_u8(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u8 called!\n"); abort(); }
/* Generated stub for queue_broadcast */
void queue_broadcast(struct broadcast_state *bstate UNNEEDED,
			     const int type UNNEEDED,
			     const u8 *tag UNNEEDED,
			     const u8 *payload UNNEEDED)
{ fprintf(stderr, "queue_broadcast called!\n"); abort(); }
/* Generated stub for towire_pubkey */
void towire_pubkey(u8 **pptr UNNEEDED, const struct pubkey *pubkey UNNEEDED)
{ fprintf(stderr, "towire_pubkey called!\n"); abort(); }
/* Generated stub for towire_short_channel_id */
void towire_short_channel_id(u8 **pptr UNNEEDED,
			     const struct short_channel_id *short_channel_id UNNEEDED)
{ fprintf(stderr, "towire_short_channel_id called!\n"); abort(); }
/* Generated stub for towire_u16 */
void towire_u16(u8 **pptr UNNEEDED, u16 v UNNEEDED)
{ fprintf(stderr, "towire_u16 called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

const void *trc;

int main(void)
{
	static const struct sha256_double zerohash;
	const tal_t *ctx = trc = tal_tmpctx(NULL);
	struct node_connection *nc;
	struct routing_state *rstate;
	struct pubkey a, b, c;
	s64 fee;
	struct node_connection **route;

	secp256k1_ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY
						 | SECP256K1_CONTEXT_SIGN);

	rstate = new_routing_state(ctx, &zerohash);

	pubkey_from_hexstr("03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf",
			   strlen("03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf"),
			   &a);
	pubkey_from_hexstr("0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae",
			   strlen("0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae"),
			   &b);
	pubkey_from_hexstr("02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06",
			   strlen("02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06"),
			   &c);


	/* [{'active': True, 'short_id': '6990:2:1/1', 'fee_per_kw': 10, 'delay': 5, 'flags': 1, 'destination': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'source': '02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06', 'last_update': 1504064344}, */
	nc = get_or_make_connection(rstate, &c, &b);
	nc->active = true;
	nc->base_fee = 0;
	nc->proportional_fee = 10;
	nc->delay = 5;
	nc->flags = 1;
	nc->last_timestamp = 1504064344;

	/* {'active': True, 'short_id': '6989:2:1/0', 'fee_per_kw': 10, 'delay': 5, 'flags': 0, 'destination': '03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf', 'source': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'last_update': 1504064344}, */
	nc = get_or_make_connection(rstate, &b, &a);
	nc->active = true;
	nc->base_fee = 0;
	nc->proportional_fee = 10;
	nc->delay = 5;
	nc->flags = 0;
	nc->last_timestamp = 1504064344;

	/* {'active': True, 'short_id': '6990:2:1/0', 'fee_per_kw': 10, 'delay': 5, 'flags': 0, 'destination': '02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06', 'source': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'last_update': 1504064344}, */
	nc = get_or_make_connection(rstate, &b, &c);
	nc->active = true;
	nc->base_fee = 0;
	nc->proportional_fee = 10;
	nc->delay = 5;
	nc->flags = 0;
	nc->last_timestamp = 1504064344;

	/* {'active': True, 'short_id': '6989:2:1/1', 'fee_per_kw': 10, 'delay': 5, 'flags': 1, 'destination': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'source': '03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf', 'last_update': 1504064344}]} */
	nc = get_or_make_connection(rstate, &a, &b);
	nc->active = true;
	nc->base_fee = 0;
	nc->proportional_fee = 10;
	nc->delay = 5;
	nc->flags = 1;
	nc->last_timestamp = 1504064344;

	nc = find_route(ctx, rstate, &a, &c, 100000, 1.0, &fee, &route);
	assert(nc);
	assert(tal_count(route) == 1);
	assert(pubkey_eq(&route[0]->src->id, &b));
	assert(pubkey_eq(&route[0]->dst->id, &c));

	tal_free(ctx);
	secp256k1_context_destroy(secp256k1_ctx);
	return 0;
}
