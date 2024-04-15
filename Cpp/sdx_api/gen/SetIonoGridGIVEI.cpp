
#include "SetIonoGridGIVEI.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoGridGIVEI
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoGridGIVEI::CmdName = "SetIonoGridGIVEI";
    const char* const SetIonoGridGIVEI::Documentation = "Set the GIVEI for a ionospheric grid point\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- -------------------------------\n"
      "Band            int             The ionospheric grid band index\n"
      "Point           int             The IGP index\n"
      "GiveI           int             The GIVEI at the IGP\n"
      "ServiceProvider optional string The service provider (optional)";
    const char* const SetIonoGridGIVEI::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIonoGridGIVEI);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIonoGridGIVEI);


    SetIonoGridGIVEI::SetIonoGridGIVEI()
      : CommandBase(CmdName, TargetId)
    {}

    SetIonoGridGIVEI::SetIonoGridGIVEI(int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setPoint(point);
      setGiveI(giveI);
      setServiceProvider(serviceProvider);
    }

    SetIonoGridGIVEIPtr SetIonoGridGIVEI::create(int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider)
    {
      return std::make_shared<SetIonoGridGIVEI>(band, point, giveI, serviceProvider);
    }

    SetIonoGridGIVEIPtr SetIonoGridGIVEI::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoGridGIVEI>(ptr);
    }

    bool SetIonoGridGIVEI::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
          && parse_json<int>::is_valid(m_values["GiveI"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string SetIonoGridGIVEI::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIonoGridGIVEI::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "Point", "GiveI", "ServiceProvider"}; 
      return names; 
    }


    int SetIonoGridGIVEI::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIonoGridGIVEI::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void SetIonoGridGIVEI::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIonoGridGIVEI::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void SetIonoGridGIVEI::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetIonoGridGIVEI::giveI() const
    {
      return parse_json<int>::parse(m_values["GiveI"]);
    }

    void SetIonoGridGIVEI::setGiveI(int giveI)
    {
      m_values.AddMember("GiveI", parse_json<int>::format(giveI, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetIonoGridGIVEI::serviceProvider() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void SetIonoGridGIVEI::setServiceProvider(const Sdx::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<Sdx::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
