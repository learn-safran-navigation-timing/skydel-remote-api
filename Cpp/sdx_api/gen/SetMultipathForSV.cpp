
#include "gen/SetMultipathForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetMultipathForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetMultipathForSV::CmdName = "SetMultipathForSV";
    const char* const SetMultipathForSV::Documentation = "Add or update signal echo (multipath). Offsets (power loss, pseudorange, Doppler and carrier phase) are all relative to line-of-sight signal.\nIf Id is not set, or unknown to Skydel, a new echo will be added. Otherwise, existing echo will be updated.";

    REGISTER_COMMAND_FACTORY(SetMultipathForSV);


    SetMultipathForSV::SetMultipathForSV()
      : CommandBase(CmdName)
    {}

    SetMultipathForSV::SetMultipathForSV(const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setSvId(svId);
      setPowerLoss(powerLoss);
      setPseudorange(pseudorange);
      setDoppler(doppler);
      setCarrierPhase(carrierPhase);
      setEcho(echo);
      setId(id);
    }

    SetMultipathForSVPtr SetMultipathForSV::create(const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id)
    {
      return std::make_shared<SetMultipathForSV>(signal, svId, powerLoss, pseudorange, doppler, carrierPhase, echo, id);
    }

    SetMultipathForSVPtr SetMultipathForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetMultipathForSV>(ptr);
    }

    bool SetMultipathForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["PowerLoss"])
          && parse_json<double>::is_valid(m_values["Pseudorange"])
          && parse_json<double>::is_valid(m_values["Doppler"])
          && parse_json<double>::is_valid(m_values["CarrierPhase"])
          && parse_json<int>::is_valid(m_values["Echo"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetMultipathForSV::documentation() const { return Documentation; }


    int SetMultipathForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetMultipathForSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetMultipathForSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMultipathForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetMultipathForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetMultipathForSV::powerLoss() const
    {
      return parse_json<double>::parse(m_values["PowerLoss"]);
    }

    void SetMultipathForSV::setPowerLoss(double powerLoss)
    {
      m_values.AddMember("PowerLoss", parse_json<double>::format(powerLoss, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetMultipathForSV::pseudorange() const
    {
      return parse_json<double>::parse(m_values["Pseudorange"]);
    }

    void SetMultipathForSV::setPseudorange(double pseudorange)
    {
      m_values.AddMember("Pseudorange", parse_json<double>::format(pseudorange, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetMultipathForSV::doppler() const
    {
      return parse_json<double>::parse(m_values["Doppler"]);
    }

    void SetMultipathForSV::setDoppler(double doppler)
    {
      m_values.AddMember("Doppler", parse_json<double>::format(doppler, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetMultipathForSV::carrierPhase() const
    {
      return parse_json<double>::parse(m_values["CarrierPhase"]);
    }

    void SetMultipathForSV::setCarrierPhase(double carrierPhase)
    {
      m_values.AddMember("CarrierPhase", parse_json<double>::format(carrierPhase, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMultipathForSV::echo() const
    {
      return parse_json<int>::parse(m_values["Echo"]);
    }

    void SetMultipathForSV::setEcho(int echo)
    {
      m_values.AddMember("Echo", parse_json<int>::format(echo, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMultipathForSV::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetMultipathForSV::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
