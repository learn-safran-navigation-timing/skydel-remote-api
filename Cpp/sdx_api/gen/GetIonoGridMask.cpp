
#include "GetIonoGridMask.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridMask
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridMask::CmdName = "GetIonoGridMask";
    const char* const GetIonoGridMask::Documentation = "Get the flag for a ionospheric grid point in the SBAS message 18 mask\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ -------------------------------\n"
      "ServiceProvider string The service provider\n"
      "Band            int    The ionospheric grid band index\n"
      "Point           int    The IGP index";
    const char* const GetIonoGridMask::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoGridMask);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoGridMask);


    GetIonoGridMask::GetIonoGridMask()
      : CommandBase(CmdName, TargetId)
    {}

    GetIonoGridMask::GetIonoGridMask(const std::string& serviceProvider, int band, int point)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setBand(band);
      setPoint(point);
    }

    GetIonoGridMaskPtr GetIonoGridMask::create(const std::string& serviceProvider, int band, int point)
    {
      return std::make_shared<GetIonoGridMask>(serviceProvider, band, point);
    }

    GetIonoGridMaskPtr GetIonoGridMask::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridMask>(ptr);
    }

    bool GetIonoGridMask::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
        ;

    }

    std::string GetIonoGridMask::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoGridMask::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "Band", "Point"}; 
      return names; 
    }


    int GetIonoGridMask::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIonoGridMask::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridMask::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridMask::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void GetIonoGridMask::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridMask::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void GetIonoGridMask::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
