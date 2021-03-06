/*
 * rquota_xdr.c		XDR support for rpc.quotad.
 *
 * Generated by rpcgen and edited manually.
 */

#include "rquotad.h"

bool_t
xdr_getquota_args(XDR *xdrs, getquota_args *objp)
{
	return xdr_string(xdrs, &objp->gqa_pathp, RQ_PATHLEN) &&
	       xdr_int(xdrs, &objp->gqa_uid);
}

bool_t
xdr_rquota(XDR *xdrs, rquota *objp)
{
	unsigned long	*buf = NULL;

	if (xdrs->x_op == XDR_ENCODE || xdrs->x_op == XDR_DECODE)
		buf = XDR_INLINE(xdrs,10 * BYTES_PER_XDR_UNIT);

	if (buf == NULL) {
		return xdr_int(xdrs, &objp->rq_bsize) &&
		       xdr_bool(xdrs, &objp->rq_active) &&
		       xdr_u_int(xdrs, &objp->rq_bhardlimit) &&
		       xdr_u_int(xdrs, &objp->rq_bsoftlimit) &&
		       xdr_u_int(xdrs, &objp->rq_curblocks) &&
		       xdr_u_int(xdrs, &objp->rq_fhardlimit) &&
		       xdr_u_int(xdrs, &objp->rq_fsoftlimit) &&
		       xdr_u_int(xdrs, &objp->rq_curfiles) &&
		       xdr_u_int(xdrs, &objp->rq_btimeleft) &&
		       xdr_u_int(xdrs, &objp->rq_ftimeleft);
	}

	if (xdrs->x_op == XDR_ENCODE) {
		IXDR_PUT_LONG(buf,objp->rq_bsize);
		IXDR_PUT_BOOL(buf,objp->rq_active);
		IXDR_PUT_U_LONG(buf,objp->rq_bhardlimit);
		IXDR_PUT_U_LONG(buf,objp->rq_bsoftlimit);
		IXDR_PUT_U_LONG(buf,objp->rq_curblocks);
		IXDR_PUT_U_LONG(buf,objp->rq_fhardlimit);
		IXDR_PUT_U_LONG(buf,objp->rq_fsoftlimit);
		IXDR_PUT_U_LONG(buf,objp->rq_curfiles);
		IXDR_PUT_U_LONG(buf,objp->rq_btimeleft);
		IXDR_PUT_U_LONG(buf,objp->rq_ftimeleft);
	} else if (xdrs->x_op == XDR_DECODE) {
		objp->rq_bsize = IXDR_GET_LONG(buf);
		objp->rq_active = IXDR_GET_BOOL(buf);
		objp->rq_bhardlimit = IXDR_GET_U_LONG(buf);
		objp->rq_bsoftlimit = IXDR_GET_U_LONG(buf);
		objp->rq_curblocks = IXDR_GET_U_LONG(buf);
		objp->rq_fhardlimit = IXDR_GET_U_LONG(buf);
		objp->rq_fsoftlimit = IXDR_GET_U_LONG(buf);
		objp->rq_curfiles = IXDR_GET_U_LONG(buf);
		objp->rq_btimeleft = IXDR_GET_U_LONG(buf);
		objp->rq_ftimeleft = IXDR_GET_U_LONG(buf);
	}

	return(TRUE);
}

bool_t
xdr_gqr_status(XDR *xdrs, gqr_status *objp)
{
	return xdr_enum(xdrs, (enum_t *) objp);
}

bool_t
xdr_getquota_rslt(XDR *xdrs, getquota_rslt *objp)
{
	if (!xdr_gqr_status(xdrs, &objp->status)) {
		 return (FALSE);
	}
	switch (objp->status) {
	case Q_OK:
		if (!xdr_rquota(xdrs, &objp->getquota_rslt_u.gqr_rquota))
			return (FALSE);
		break;
	case Q_NOQUOTA:
	case Q_EPERM:
		break;
	default:
		return (FALSE);
	}
	return (TRUE);
}
