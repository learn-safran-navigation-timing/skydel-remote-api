
#include "GetOfficialLeapSecond.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOfficialLeapSecond
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOfficialLeapSecond::CmdName = "GetOfficialLeapSecond";
    const char* const GetOfficialLeapSecond::Documentation = "Returns the official leap second for a given date\n"
      "\n"
      "Name Type     Description\n"
      "---- -------- ------------------------------\n"
      "Date datetime A date expressed in UTC format";
    const char* const GetOfficialLeapSecond::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetOfficialLeapSecond);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOfficialLeapSecond);


    GetOfficialLeapSecond::GetOfficialLeapSecond()
      : CommandBase(CmdName, TargetId)
    {}

    GetOfficialLeapSecond::GetOfficialLeapSecond(const Sdx::DateTime& date)
      : CommandBase(CmdName, TargetId)
    {

      setDate(date);
    }

    GetOfficialLeapSecondPtr GetOfficialLeapSecond::create(const Sdx::DateTime& date)
    {
      return std::make_shared<GetOfficialLeapSecond>(date);
    }

    GetOfficialLeapSecondPtr GetOfficialLeapSecond::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOfficialLeapSecond>(ptr);
    }

    bool GetOfficialLeapSecond::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::DateTime>::is_valid(m_values["Date"])
        ;

    }

    std::string GetOfficialLeapSecond::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOfficialLeapSecond::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Date"}; 
      return names; 
    }


    int GetOfficialLeapSecond::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    Sdx::DateTime GetOfficialLeapSecond::date() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Date"]);
    }

    void GetOfficialLeapSecond::setDate(const Sdx::DateTime& date)
    {
      m_values.AddMember("Date", parse_json<Sdx::DateTime>::format(date, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
