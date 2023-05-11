
#include "gen/GetVehicleAntennaModelResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaModelResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaModelResult::CmdName = "GetVehicleAntennaModelResult";
    const char* const GetVehicleAntennaModelResult::Documentation = "Result of GetVehicleAntennaModel.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetVehicleAntennaModelResult);


    GetVehicleAntennaModelResult::GetVehicleAntennaModelResult()
      : CommandResult(CmdName)
    {}

    GetVehicleAntennaModelResult::GetVehicleAntennaModelResult(const std::vector<std::vector<double>>& gainL1, const Sdx::AntennaPatternType& gainTypeL1, double gainOffsetL1, const std::vector<std::vector<double>>& gainL2, const Sdx::AntennaPatternType& gainTypeL2, double gainOffsetL2, const std::vector<std::vector<double>>& gainL5, const Sdx::AntennaPatternType& gainTypeL5, double gainOffsetL5, const std::vector<std::vector<double>>& gainE6, const Sdx::AntennaPatternType& gainTypeE6, double gainOffsetE6, const std::vector<std::vector<double>>& phaseOffsetL1, const Sdx::AntennaPatternType& phaseOffsetTypeL1, double phasePatternOffsetL1, const std::vector<std::vector<double>>& phaseOffsetL2, const Sdx::AntennaPatternType& phaseOffsetTypeL2, double phasePatternOffsetL2, const std::vector<std::vector<double>>& phaseOffsetL5, const Sdx::AntennaPatternType& phaseOffsetTypeL5, double phasePatternOffsetL5, const std::vector<std::vector<double>>& phaseOffsetE6, const Sdx::AntennaPatternType& phaseOffsetTypeE6, double phasePatternOffsetE6, double x, double y, double z, double yaw, double pitch, double roll, const std::string& name)
      : CommandResult(CmdName)
    {

      setGainL1(gainL1);
      setGainTypeL1(gainTypeL1);
      setGainOffsetL1(gainOffsetL1);
      setGainL2(gainL2);
      setGainTypeL2(gainTypeL2);
      setGainOffsetL2(gainOffsetL2);
      setGainL5(gainL5);
      setGainTypeL5(gainTypeL5);
      setGainOffsetL5(gainOffsetL5);
      setGainE6(gainE6);
      setGainTypeE6(gainTypeE6);
      setGainOffsetE6(gainOffsetE6);
      setPhaseOffsetL1(phaseOffsetL1);
      setPhaseOffsetTypeL1(phaseOffsetTypeL1);
      setPhasePatternOffsetL1(phasePatternOffsetL1);
      setPhaseOffsetL2(phaseOffsetL2);
      setPhaseOffsetTypeL2(phaseOffsetTypeL2);
      setPhasePatternOffsetL2(phasePatternOffsetL2);
      setPhaseOffsetL5(phaseOffsetL5);
      setPhaseOffsetTypeL5(phaseOffsetTypeL5);
      setPhasePatternOffsetL5(phasePatternOffsetL5);
      setPhaseOffsetE6(phaseOffsetE6);
      setPhaseOffsetTypeE6(phaseOffsetTypeE6);
      setPhasePatternOffsetE6(phasePatternOffsetE6);
      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setName(name);
    }

    GetVehicleAntennaModelResult::GetVehicleAntennaModelResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gainL1, const Sdx::AntennaPatternType& gainTypeL1, double gainOffsetL1, const std::vector<std::vector<double>>& gainL2, const Sdx::AntennaPatternType& gainTypeL2, double gainOffsetL2, const std::vector<std::vector<double>>& gainL5, const Sdx::AntennaPatternType& gainTypeL5, double gainOffsetL5, const std::vector<std::vector<double>>& gainE6, const Sdx::AntennaPatternType& gainTypeE6, double gainOffsetE6, const std::vector<std::vector<double>>& phaseOffsetL1, const Sdx::AntennaPatternType& phaseOffsetTypeL1, double phasePatternOffsetL1, const std::vector<std::vector<double>>& phaseOffsetL2, const Sdx::AntennaPatternType& phaseOffsetTypeL2, double phasePatternOffsetL2, const std::vector<std::vector<double>>& phaseOffsetL5, const Sdx::AntennaPatternType& phaseOffsetTypeL5, double phasePatternOffsetL5, const std::vector<std::vector<double>>& phaseOffsetE6, const Sdx::AntennaPatternType& phaseOffsetTypeE6, double phasePatternOffsetE6, double x, double y, double z, double yaw, double pitch, double roll, const std::string& name)
      : CommandResult(CmdName, relatedCommand)
    {

      setGainL1(gainL1);
      setGainTypeL1(gainTypeL1);
      setGainOffsetL1(gainOffsetL1);
      setGainL2(gainL2);
      setGainTypeL2(gainTypeL2);
      setGainOffsetL2(gainOffsetL2);
      setGainL5(gainL5);
      setGainTypeL5(gainTypeL5);
      setGainOffsetL5(gainOffsetL5);
      setGainE6(gainE6);
      setGainTypeE6(gainTypeE6);
      setGainOffsetE6(gainOffsetE6);
      setPhaseOffsetL1(phaseOffsetL1);
      setPhaseOffsetTypeL1(phaseOffsetTypeL1);
      setPhasePatternOffsetL1(phasePatternOffsetL1);
      setPhaseOffsetL2(phaseOffsetL2);
      setPhaseOffsetTypeL2(phaseOffsetTypeL2);
      setPhasePatternOffsetL2(phasePatternOffsetL2);
      setPhaseOffsetL5(phaseOffsetL5);
      setPhaseOffsetTypeL5(phaseOffsetTypeL5);
      setPhasePatternOffsetL5(phasePatternOffsetL5);
      setPhaseOffsetE6(phaseOffsetE6);
      setPhaseOffsetTypeE6(phaseOffsetTypeE6);
      setPhasePatternOffsetE6(phasePatternOffsetE6);
      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setName(name);
    }


    GetVehicleAntennaModelResultPtr GetVehicleAntennaModelResult::create(const std::vector<std::vector<double>>& gainL1, const Sdx::AntennaPatternType& gainTypeL1, double gainOffsetL1, const std::vector<std::vector<double>>& gainL2, const Sdx::AntennaPatternType& gainTypeL2, double gainOffsetL2, const std::vector<std::vector<double>>& gainL5, const Sdx::AntennaPatternType& gainTypeL5, double gainOffsetL5, const std::vector<std::vector<double>>& gainE6, const Sdx::AntennaPatternType& gainTypeE6, double gainOffsetE6, const std::vector<std::vector<double>>& phaseOffsetL1, const Sdx::AntennaPatternType& phaseOffsetTypeL1, double phasePatternOffsetL1, const std::vector<std::vector<double>>& phaseOffsetL2, const Sdx::AntennaPatternType& phaseOffsetTypeL2, double phasePatternOffsetL2, const std::vector<std::vector<double>>& phaseOffsetL5, const Sdx::AntennaPatternType& phaseOffsetTypeL5, double phasePatternOffsetL5, const std::vector<std::vector<double>>& phaseOffsetE6, const Sdx::AntennaPatternType& phaseOffsetTypeE6, double phasePatternOffsetE6, double x, double y, double z, double yaw, double pitch, double roll, const std::string& name)
    {
      return std::make_shared<GetVehicleAntennaModelResult>(gainL1, gainTypeL1, gainOffsetL1, gainL2, gainTypeL2, gainOffsetL2, gainL5, gainTypeL5, gainOffsetL5, gainE6, gainTypeE6, gainOffsetE6, phaseOffsetL1, phaseOffsetTypeL1, phasePatternOffsetL1, phaseOffsetL2, phaseOffsetTypeL2, phasePatternOffsetL2, phaseOffsetL5, phaseOffsetTypeL5, phasePatternOffsetL5, phaseOffsetE6, phaseOffsetTypeE6, phasePatternOffsetE6, x, y, z, yaw, pitch, roll, name);
    }

    GetVehicleAntennaModelResultPtr GetVehicleAntennaModelResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gainL1, const Sdx::AntennaPatternType& gainTypeL1, double gainOffsetL1, const std::vector<std::vector<double>>& gainL2, const Sdx::AntennaPatternType& gainTypeL2, double gainOffsetL2, const std::vector<std::vector<double>>& gainL5, const Sdx::AntennaPatternType& gainTypeL5, double gainOffsetL5, const std::vector<std::vector<double>>& gainE6, const Sdx::AntennaPatternType& gainTypeE6, double gainOffsetE6, const std::vector<std::vector<double>>& phaseOffsetL1, const Sdx::AntennaPatternType& phaseOffsetTypeL1, double phasePatternOffsetL1, const std::vector<std::vector<double>>& phaseOffsetL2, const Sdx::AntennaPatternType& phaseOffsetTypeL2, double phasePatternOffsetL2, const std::vector<std::vector<double>>& phaseOffsetL5, const Sdx::AntennaPatternType& phaseOffsetTypeL5, double phasePatternOffsetL5, const std::vector<std::vector<double>>& phaseOffsetE6, const Sdx::AntennaPatternType& phaseOffsetTypeE6, double phasePatternOffsetE6, double x, double y, double z, double yaw, double pitch, double roll, const std::string& name)
    {
      return std::make_shared<GetVehicleAntennaModelResult>(relatedCommand, gainL1, gainTypeL1, gainOffsetL1, gainL2, gainTypeL2, gainOffsetL2, gainL5, gainTypeL5, gainOffsetL5, gainE6, gainTypeE6, gainOffsetE6, phaseOffsetL1, phaseOffsetTypeL1, phasePatternOffsetL1, phaseOffsetL2, phaseOffsetTypeL2, phasePatternOffsetL2, phaseOffsetL5, phaseOffsetTypeL5, phasePatternOffsetL5, phaseOffsetE6, phaseOffsetTypeE6, phasePatternOffsetE6, x, y, z, yaw, pitch, roll, name);
    }

    GetVehicleAntennaModelResultPtr GetVehicleAntennaModelResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaModelResult>(ptr);
    }

    bool GetVehicleAntennaModelResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainL1"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeL1"])
          && parse_json<double>::is_valid(m_values["GainOffsetL1"])
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainL2"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeL2"])
          && parse_json<double>::is_valid(m_values["GainOffsetL2"])
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainL5"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeL5"])
          && parse_json<double>::is_valid(m_values["GainOffsetL5"])
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainE6"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeE6"])
          && parse_json<double>::is_valid(m_values["GainOffsetE6"])
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetL1"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeL1"])
          && parse_json<double>::is_valid(m_values["PhasePatternOffsetL1"])
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetL2"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeL2"])
          && parse_json<double>::is_valid(m_values["PhasePatternOffsetL2"])
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetL5"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeL5"])
          && parse_json<double>::is_valid(m_values["PhasePatternOffsetL5"])
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetE6"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeE6"])
          && parse_json<double>::is_valid(m_values["PhasePatternOffsetE6"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
          && parse_json<std::string>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaModelResult::documentation() const { return Documentation; }


    std::vector<std::vector<double>> GetVehicleAntennaModelResult::gainL1() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainL1"]);
    }

    void GetVehicleAntennaModelResult::setGainL1(const std::vector<std::vector<double>>& gainL1)
    {
      m_values.AddMember("GainL1", parse_json<std::vector<std::vector<double>>>::format(gainL1, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaModelResult::gainTypeL1() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeL1"]);
    }

    void GetVehicleAntennaModelResult::setGainTypeL1(const Sdx::AntennaPatternType& gainTypeL1)
    {
      m_values.AddMember("GainTypeL1", parse_json<Sdx::AntennaPatternType>::format(gainTypeL1, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::gainOffsetL1() const
    {
      return parse_json<double>::parse(m_values["GainOffsetL1"]);
    }

    void GetVehicleAntennaModelResult::setGainOffsetL1(double gainOffsetL1)
    {
      m_values.AddMember("GainOffsetL1", parse_json<double>::format(gainOffsetL1, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::vector<double>> GetVehicleAntennaModelResult::gainL2() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainL2"]);
    }

    void GetVehicleAntennaModelResult::setGainL2(const std::vector<std::vector<double>>& gainL2)
    {
      m_values.AddMember("GainL2", parse_json<std::vector<std::vector<double>>>::format(gainL2, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaModelResult::gainTypeL2() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeL2"]);
    }

    void GetVehicleAntennaModelResult::setGainTypeL2(const Sdx::AntennaPatternType& gainTypeL2)
    {
      m_values.AddMember("GainTypeL2", parse_json<Sdx::AntennaPatternType>::format(gainTypeL2, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::gainOffsetL2() const
    {
      return parse_json<double>::parse(m_values["GainOffsetL2"]);
    }

    void GetVehicleAntennaModelResult::setGainOffsetL2(double gainOffsetL2)
    {
      m_values.AddMember("GainOffsetL2", parse_json<double>::format(gainOffsetL2, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::vector<double>> GetVehicleAntennaModelResult::gainL5() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainL5"]);
    }

    void GetVehicleAntennaModelResult::setGainL5(const std::vector<std::vector<double>>& gainL5)
    {
      m_values.AddMember("GainL5", parse_json<std::vector<std::vector<double>>>::format(gainL5, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaModelResult::gainTypeL5() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeL5"]);
    }

    void GetVehicleAntennaModelResult::setGainTypeL5(const Sdx::AntennaPatternType& gainTypeL5)
    {
      m_values.AddMember("GainTypeL5", parse_json<Sdx::AntennaPatternType>::format(gainTypeL5, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::gainOffsetL5() const
    {
      return parse_json<double>::parse(m_values["GainOffsetL5"]);
    }

    void GetVehicleAntennaModelResult::setGainOffsetL5(double gainOffsetL5)
    {
      m_values.AddMember("GainOffsetL5", parse_json<double>::format(gainOffsetL5, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::vector<double>> GetVehicleAntennaModelResult::gainE6() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainE6"]);
    }

    void GetVehicleAntennaModelResult::setGainE6(const std::vector<std::vector<double>>& gainE6)
    {
      m_values.AddMember("GainE6", parse_json<std::vector<std::vector<double>>>::format(gainE6, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaModelResult::gainTypeE6() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeE6"]);
    }

    void GetVehicleAntennaModelResult::setGainTypeE6(const Sdx::AntennaPatternType& gainTypeE6)
    {
      m_values.AddMember("GainTypeE6", parse_json<Sdx::AntennaPatternType>::format(gainTypeE6, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::gainOffsetE6() const
    {
      return parse_json<double>::parse(m_values["GainOffsetE6"]);
    }

    void GetVehicleAntennaModelResult::setGainOffsetE6(double gainOffsetE6)
    {
      m_values.AddMember("GainOffsetE6", parse_json<double>::format(gainOffsetE6, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::vector<double>> GetVehicleAntennaModelResult::phaseOffsetL1() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetL1"]);
    }

    void GetVehicleAntennaModelResult::setPhaseOffsetL1(const std::vector<std::vector<double>>& phaseOffsetL1)
    {
      m_values.AddMember("PhaseOffsetL1", parse_json<std::vector<std::vector<double>>>::format(phaseOffsetL1, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaModelResult::phaseOffsetTypeL1() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeL1"]);
    }

    void GetVehicleAntennaModelResult::setPhaseOffsetTypeL1(const Sdx::AntennaPatternType& phaseOffsetTypeL1)
    {
      m_values.AddMember("PhaseOffsetTypeL1", parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeL1, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::phasePatternOffsetL1() const
    {
      return parse_json<double>::parse(m_values["PhasePatternOffsetL1"]);
    }

    void GetVehicleAntennaModelResult::setPhasePatternOffsetL1(double phasePatternOffsetL1)
    {
      m_values.AddMember("PhasePatternOffsetL1", parse_json<double>::format(phasePatternOffsetL1, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::vector<double>> GetVehicleAntennaModelResult::phaseOffsetL2() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetL2"]);
    }

    void GetVehicleAntennaModelResult::setPhaseOffsetL2(const std::vector<std::vector<double>>& phaseOffsetL2)
    {
      m_values.AddMember("PhaseOffsetL2", parse_json<std::vector<std::vector<double>>>::format(phaseOffsetL2, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaModelResult::phaseOffsetTypeL2() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeL2"]);
    }

    void GetVehicleAntennaModelResult::setPhaseOffsetTypeL2(const Sdx::AntennaPatternType& phaseOffsetTypeL2)
    {
      m_values.AddMember("PhaseOffsetTypeL2", parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeL2, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::phasePatternOffsetL2() const
    {
      return parse_json<double>::parse(m_values["PhasePatternOffsetL2"]);
    }

    void GetVehicleAntennaModelResult::setPhasePatternOffsetL2(double phasePatternOffsetL2)
    {
      m_values.AddMember("PhasePatternOffsetL2", parse_json<double>::format(phasePatternOffsetL2, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::vector<double>> GetVehicleAntennaModelResult::phaseOffsetL5() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetL5"]);
    }

    void GetVehicleAntennaModelResult::setPhaseOffsetL5(const std::vector<std::vector<double>>& phaseOffsetL5)
    {
      m_values.AddMember("PhaseOffsetL5", parse_json<std::vector<std::vector<double>>>::format(phaseOffsetL5, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaModelResult::phaseOffsetTypeL5() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeL5"]);
    }

    void GetVehicleAntennaModelResult::setPhaseOffsetTypeL5(const Sdx::AntennaPatternType& phaseOffsetTypeL5)
    {
      m_values.AddMember("PhaseOffsetTypeL5", parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeL5, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::phasePatternOffsetL5() const
    {
      return parse_json<double>::parse(m_values["PhasePatternOffsetL5"]);
    }

    void GetVehicleAntennaModelResult::setPhasePatternOffsetL5(double phasePatternOffsetL5)
    {
      m_values.AddMember("PhasePatternOffsetL5", parse_json<double>::format(phasePatternOffsetL5, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::vector<double>> GetVehicleAntennaModelResult::phaseOffsetE6() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetE6"]);
    }

    void GetVehicleAntennaModelResult::setPhaseOffsetE6(const std::vector<std::vector<double>>& phaseOffsetE6)
    {
      m_values.AddMember("PhaseOffsetE6", parse_json<std::vector<std::vector<double>>>::format(phaseOffsetE6, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetVehicleAntennaModelResult::phaseOffsetTypeE6() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeE6"]);
    }

    void GetVehicleAntennaModelResult::setPhaseOffsetTypeE6(const Sdx::AntennaPatternType& phaseOffsetTypeE6)
    {
      m_values.AddMember("PhaseOffsetTypeE6", parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeE6, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::phasePatternOffsetE6() const
    {
      return parse_json<double>::parse(m_values["PhasePatternOffsetE6"]);
    }

    void GetVehicleAntennaModelResult::setPhasePatternOffsetE6(double phasePatternOffsetE6)
    {
      m_values.AddMember("PhasePatternOffsetE6", parse_json<double>::format(phasePatternOffsetE6, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void GetVehicleAntennaModelResult::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void GetVehicleAntennaModelResult::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void GetVehicleAntennaModelResult::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetVehicleAntennaModelResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetVehicleAntennaModelResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetVehicleAntennaModelResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetVehicleAntennaModelResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetVehicleAntennaModelResult::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaModelResult::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
