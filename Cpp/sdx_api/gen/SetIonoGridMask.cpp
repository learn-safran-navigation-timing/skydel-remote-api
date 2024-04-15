
#include "SetIonoGridMask.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoGridMask
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoGridMask::CmdName = "SetIonoGridMask";
    const char* const SetIonoGridMask::Documentation = "Set the flag for a ionospheric grid point in the SBAS message 18 mask\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ -------------------------------\n"
      "ServiceProvider string The service provider\n"
      "Band            int    The ionospheric grid band index\n"
      "Point           int    The IGP index\n"
      "Flag            bool   Is the IGP monitored";
    const char* const SetIonoGridMask::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIonoGridMask);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIonoGridMask);


    SetIonoGridMask::SetIonoGridMask()
      : CommandBase(CmdName, TargetId)
    {}

    SetIonoGridMask::SetIonoGridMask(const std::string& serviceProvider, int band, int point, bool flag)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setBand(band);
      setPoint(point);
      setFlag(flag);
    }

    SetIonoGridMaskPtr SetIonoGridMask::create(const std::string& serviceProvider, int band, int point, bool flag)
    {
      return std::make_shared<SetIonoGridMask>(serviceProvider, band, point, flag);
    }

    SetIonoGridMaskPtr SetIonoGridMask::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoGridMask>(ptr);
    }

    bool SetIonoGridMask::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
          && parse_json<bool>::is_valid(m_values["Flag"])
        ;

    }

    std::string SetIonoGridMask::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIonoGridMask::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "Band", "Point", "Flag"}; 
      return names; 
    }


    int SetIonoGridMask::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetIonoGridMask::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void SetIonoGridMask::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIonoGridMask::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void SetIonoGridMask::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIonoGridMask::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void SetIonoGridMask::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetIonoGridMask::flag() const
    {
      return parse_json<bool>::parse(m_values["Flag"]);
    }

    void SetIonoGridMask::setFlag(bool flag)
    {
      m_values.AddMember("Flag", parse_json<bool>::format(flag, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
