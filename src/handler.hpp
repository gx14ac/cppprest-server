// Copyright © 2019 netSk8ight. All Rights Reserved. 

#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "messagetypes.hpp"

class Handler
{
public:
	Handler();
	Handler(utility::string_t url);
	~Handler();

	pplx::task<void> open() { return m_listener.open(); }
	pplx::task<void> close() { return m_listener.close(); }

private:
	void handle_get(http_request message);
	void handle_put(http_request message);
	void handle_post(http_request message);
	void handle_delete(http_request message);

	http_listener m_listener;
};

#endif /* __HANDLER_H__ */