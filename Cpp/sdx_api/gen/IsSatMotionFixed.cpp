
#include "gen/IsSatMotionFixed.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSatMotionFixed
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSatMotionFixed::CmdName = "IsSatMotionFixed";
    const char* const IsSatMotionFixed::Documentation = "Tells if the satellite is fixed (True) or not fixed (false).";

    REGISTER_COMMAND_FACTORY(IsSatMotionFixed);


    IsSatMotionFixed::IsSatMotionFixed()
      : CommandBase(CmdName)
    {}

    IsSatMotionFixed::IsSatMotionFixed(const std::string& system, int svId)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }

    IsSatMotionFixedPtr IsSatMotionFixed::create(const std::string& system, int svId)
    {
      return std::make_shared<IsSatMotionFixed>(system, svId);
    }

    IsSatMotionFixedPtr IsSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSatMotionFixed>(ptr);
    }

    bool IsSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string IsSatMotionFixed::documentation() const { return Documentation; }


    int IsSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSatMotionFixed::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSatMotionFixed::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSatMotionFixed::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsSatMotionFixed::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
