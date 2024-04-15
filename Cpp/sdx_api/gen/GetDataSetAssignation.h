#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get data set assignation for the specified constellation.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetType string "Almanac", "Ephemeris" or "Orbit"
    ///

    class GetDataSetAssignation;
    typedef std::shared_ptr<GetDataSetAssignation> GetDataSetAssignationPtr;
    
    
    class GetDataSetAssignation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetDataSetAssignation();

      GetDataSetAssignation(const std::string& system, const std::string& dataSetType);

      static GetDataSetAssignationPtr create(const std::string& system, const std::string& dataSetType);
      static GetDataSetAssignationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** dataSetType ****
      std::string dataSetType() const;
      void setDataSetType(const std::string& dataSetType);
    };
    
  }
}

