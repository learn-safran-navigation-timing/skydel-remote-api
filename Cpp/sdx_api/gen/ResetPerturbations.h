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
    /// Set orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero for the specified constellation.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId        int             The satellite's SV ID. Use 0 to apply new value to all satellites in the constellation.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class ResetPerturbations;
    typedef std::shared_ptr<ResetPerturbations> ResetPerturbationsPtr;
    
    
    class ResetPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ResetPerturbations();

      ResetPerturbations(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName = {});
  
      static ResetPerturbationsPtr create(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName = {});
      static ResetPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
  }
}

