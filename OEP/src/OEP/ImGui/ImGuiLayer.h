#pragma once

#include "OEP/Layer.h"
#include "OEP/Events/KeyEvent.h"
#include "OEP/Events/MouseEvent.h"
#include "OEP/Events/ApplicationEvent.h"

namespace oep
{
	class OEP_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& e);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);
		bool OnWindowResizeEvent(WindowResizeEvent& event);
	private:
		float m_Time = 0.0f;
	};
}
