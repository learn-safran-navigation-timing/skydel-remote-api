#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for the specified constellation.
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

    class SetPerturbations;
    typedef std::shared_ptr<SetPerturbations> SetPerturbationsPtr;
    
    
    class SetPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPerturbations();

      SetPerturbations(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName = {});

      static SetPerturbationsPtr create(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const Sdx::optional<std::string>& dataSetName = {});
      static SetPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

