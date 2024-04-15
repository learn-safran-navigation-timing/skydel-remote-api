#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites of the specified constellation..
    /// All parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// Crs         array double    Crs (meter)
    /// Crc         array double    Crc (meter)
    /// Cis         array double    Cis (rad)
    /// Cic         array double    Cic (rad)
    /// Cus         array double    Cus (rad)
    /// Cuc         array double    Cuc (rad)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetPerturbationsForAllSat;
    typedef std::shared_ptr<SetPerturbationsForAllSat> SetPerturbationsForAllSatPtr;
    
    
    class SetPerturbationsForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPerturbationsForAllSat();

      SetPerturbationsForAllSat(const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc, const Sdx::optional<std::string>& dataSetName = {});

      static SetPerturbationsForAllSatPtr create(const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc, const Sdx::optional<std::string>& dataSetName = {});
      static SetPerturbationsForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** crs ****
      std::vector<double> crs() const;
      void setCrs(const std::vector<double>& crs);


      // **** crc ****
      std::vector<double> crc() const;
      void setCrc(const std::vector<double>& crc);


      // **** cis ****
      std::vector<double> cis() const;
      void setCis(const std::vector<double>& cis);


      // **** cic ****
      std::vector<double> cic() const;
      void setCic(const std::vector<double>& cic);


      // **** cus ****
      std::vector<double> cus() const;
      void setCus(const std::vector<double>& cus);


      // **** cuc ****
      std::vector<double> cuc() const;
      void setCuc(const std::vector<double>& cuc);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

