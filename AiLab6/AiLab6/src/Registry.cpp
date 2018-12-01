#include "stdafx.h"
#include "Registry.h"

std::unique_ptr<app::Registry> app::Reg::s_registry = nullptr;

app::Registry & app::Reg::get()
{
	if (!s_registry) { s_registry = std::make_unique<app::Registry>(); }
	return *s_registry;
}
