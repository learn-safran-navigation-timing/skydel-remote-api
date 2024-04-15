#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPerturbations.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// SvId        int             The satellite's SV ID.
    /// Crs         double          Crs (meter)
    /// Crc         double          Crc (meter)
    /// Cis         double          Cis (rad)
    /// Cic         double          Cic (rad)
    /// Cus         double          Cus (rad)
    /// Cuc         double          Cuc (rad)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetPerturbationsResult;
    typedef std::shared_ptr<GetPerturbationsResult> GetPerturbationsResultPtr;
    
    
    class GetPerturbationsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPerturbationsResult();

      GetPerturbationsResult(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName = {});

      GetPerturbationsResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName = {});

      static GetPerturbationsResultPtr create(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName = {});

      static GetPerturbationsResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName = {});
      static GetPerturbationsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** crs ****
      double crs() const;
      void setCrs(double crs);


      // **** crc ****
      double crc() const;
      void setCrc(double crc);


      // **** cis ****
      double cis() const;
      void setCis(double cis);


      // **** cic ****
      double cic() const;
      void setCic(double cic);


      // **** cus ****
      double cus() const;
      void setCus(double cus);


      // **** cuc ****
      double cuc() const;
      void setCuc(double cuc);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetPerturbationsResult);
  }
}

