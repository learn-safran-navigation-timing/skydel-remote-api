
#include "GetHilExtrapolationStateResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetHilExtrapolationStateResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetHilExtrapolationStateResult::CmdName = "GetHilExtrapolationStateResult";
    const char* const GetHilExtrapolationStateResult::Documentation = "Result of GetHilExtrapolationState.\n"
      "\n"
      "Name        Type                  Description\n"
      "----------- --------------------- ---------------------------------------------------------\n"
      "State       HilExtrapolationState HIL Extrapolation State.\n"
      "ElapsedTime int                   Time in milliseconds of the returned extrapolation state.";
    const char* const GetHilExtrapolationStateResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetHilExtrapolationStateResult);


    GetHilExtrapolationStateResult::GetHilExtrapolationStateResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetHilExtrapolationStateResult::GetHilExtrapolationStateResult(const Sdx::HilExtrapolationState& state, int elapsedTime)
      : CommandResult(CmdName, TargetId)
    {

      setState(state);
      setElapsedTime(elapsedTime);
    }

    GetHilExtrapolationStateResult::GetHilExtrapolationStateResult(CommandBasePtr relatedCommand, const Sdx::HilExtrapolationState& state, int elapsedTime)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setState(state);
      setElapsedTime(elapsedTime);
    }


    GetHilExtrapolationStateResultPtr GetHilExtrapolationStateResult::create(const Sdx::HilExtrapolationState& state, int elapsedTime)
    {
      return std::make_shared<GetHilExtrapolationStateResult>(state, elapsedTime);
    }

    GetHilExtrapolationStateResultPtr GetHilExtrapolationStateResult::create(CommandBasePtr relatedCommand, const Sdx::HilExtrapolationState& state, int elapsedTime)
    {
      return std::make_shared<GetHilExtrapolationStateResult>(relatedCommand, state, elapsedTime);
    }

    GetHilExtrapolationStateResultPtr GetHilExtrapolationStateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetHilExtrapolationStateResult>(ptr);
    }

    bool GetHilExtrapolationStateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::HilExtrapolationState>::is_valid(m_values["State"])
          && parse_json<int>::is_valid(m_values["ElapsedTime"])
        ;

    }

    std::string GetHilExtrapolationStateResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetHilExtrapolationStateResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"State", "ElapsedTime"}; 
      return names; 
    }


    Sdx::HilExtrapolationState GetHilExtrapolationStateResult::state() const
    {
      return parse_json<Sdx::HilExtrapolationState>::parse(m_values["State"]);
    }

    void GetHilExtrapolationStateResult::setState(const Sdx::HilExtrapolationState& state)
    {
      m_values.AddMember("State", parse_json<Sdx::HilExtrapolationState>::format(state, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetHilExtrapolationStateResult::elapsedTime() const
    {
      return parse_json<int>::parse(m_values["ElapsedTime"]);
    }

    void GetHilExtrapolationStateResult::setElapsedTime(int elapsedTime)
    {
      m_values.AddMember("ElapsedTime", parse_json<int>::format(elapsedTime, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
