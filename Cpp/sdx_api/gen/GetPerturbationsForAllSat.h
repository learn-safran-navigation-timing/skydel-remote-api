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
    /// Get orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites of the specified constellation..
    /// All parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetPerturbationsForAllSat;
    typedef std::shared_ptr<GetPerturbationsForAllSat> GetPerturbationsForAllSatPtr;
    
    
    class GetPerturbationsForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPerturbationsForAllSat();

      GetPerturbationsForAllSat(const std::string& system, const Sdx::optional<std::string>& dataSetName = {});

      static GetPerturbationsForAllSatPtr create(const std::string& system, const Sdx::optional<std::string>& dataSetName = {});
      static GetPerturbationsForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

