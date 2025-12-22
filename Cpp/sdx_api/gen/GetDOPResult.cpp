
#include "GetDOPResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDOPResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDOPResult::CmdName = "GetDOPResult";
    const char* const GetDOPResult::Documentation = "Result of GetDOP.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ ----------------------------------------\n"
      "Horizontal double Horizontal dilution of precision (HDOP).\n"
      "Vertical   double Vertical dilution of precision (VDOP).\n"
      "Time       double Time dilution of precision (TDOP).\n"
      "Position   double Position dilution of precision (PDOP).";
    const char* const GetDOPResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDOPResult);


    GetDOPResult::GetDOPResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetDOPResult::GetDOPResult(double horizontal, double vertical, double time, double position)
      : CommandResult(CmdName, TargetId)
    {

      setHorizontal(horizontal);
      setVertical(vertical);
      setTime(time);
      setPosition(position);
    }

    GetDOPResult::GetDOPResult(CommandBasePtr relatedCommand, double horizontal, double vertical, double time, double position)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setHorizontal(horizontal);
      setVertical(vertical);
      setTime(time);
      setPosition(position);
    }


    GetDOPResultPtr GetDOPResult::create(double horizontal, double vertical, double time, double position)
    {
      return std::make_shared<GetDOPResult>(horizontal, vertical, time, position);
    }

    GetDOPResultPtr GetDOPResult::create(CommandBasePtr relatedCommand, double horizontal, double vertical, double time, double position)
    {
      return std::make_shared<GetDOPResult>(relatedCommand, horizontal, vertical, time, position);
    }

    GetDOPResultPtr GetDOPResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDOPResult>(ptr);
    }

    bool GetDOPResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Horizontal"])
          && parse_json<double>::is_valid(m_values["Vertical"])
          && parse_json<double>::is_valid(m_values["Time"])
          && parse_json<double>::is_valid(m_values["Position"])
        ;

    }

    std::string GetDOPResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDOPResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Horizontal", "Vertical", "Time", "Position"}; 
      return names; 
    }


    double GetDOPResult::horizontal() const
    {
      return parse_json<double>::parse(m_values["Horizontal"]);
    }

    void GetDOPResult::setHorizontal(double horizontal)
    {
      m_values.AddMember("Horizontal", parse_json<double>::format(horizontal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetDOPResult::vertical() const
    {
      return parse_json<double>::parse(m_values["Vertical"]);
    }

    void GetDOPResult::setVertical(double vertical)
    {
      m_values.AddMember("Vertical", parse_json<double>::format(vertical, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetDOPResult::time() const
    {
      return parse_json<double>::parse(m_values["Time"]);
    }

    void GetDOPResult::setTime(double time)
    {
      m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetDOPResult::position() const
    {
      return parse_json<double>::parse(m_values["Position"]);
    }

    void GetDOPResult::setPosition(double position)
    {
      m_values.AddMember("Position", parse_json<double>::format(position, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
